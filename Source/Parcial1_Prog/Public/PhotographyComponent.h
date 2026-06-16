#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhotographyComponent.generated.h"

class UCameraComponent;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PARCIAL1_PROG_API UPhotographyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPhotographyComponent();

	UFUNCTION(BlueprintCallable, Category = "Photography")
	void TakePhoto();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	UCameraComponent* PlayerCamera;
};