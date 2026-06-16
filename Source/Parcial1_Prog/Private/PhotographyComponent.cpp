#include "PhotographyComponent.h"
#include "PhotographableInterface.h"
#include "CodexComponent.h"
#include "Camera/CameraComponent.h"
#include "DrawDebugHelpers.h"

UPhotographyComponent::UPhotographyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPhotographyComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if (AActor* Owner = GetOwner())
	{
		PlayerCamera = Owner->FindComponentByClass<UCameraComponent>();
	}
}

void UPhotographyComponent::TakePhoto()
{
	AActor* Owner = GetOwner();
	if (!Owner || !PlayerCamera) return;

	FVector Start = PlayerCamera->GetComponentLocation();
	FVector End = Start + (PlayerCamera->GetForwardVector() * 2000.f);

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(Owner); 

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, QueryParams);

	
	DrawDebugLine(GetWorld(), Start, End, bHit ? FColor::Green : FColor::Red, false, 2.0f, 0, 2.0f);

	if (bHit && HitResult.GetActor())
	{
		
		if (IPhotographableInterface* PhotoTarget = Cast<IPhotographableInterface>(HitResult.GetActor()))
		{
			if (PhotoTarget->IsPhotographable())
			{
				FEvidenceData Data = PhotoTarget->GetEvidenceData();
				PhotoTarget->OnPhotographed();

				
				if (UCodexComponent* Codex = Owner->FindComponentByClass<UCodexComponent>())
				{
					Codex->RegisterEvidence(Data);
				}
			}
		}
	}
}