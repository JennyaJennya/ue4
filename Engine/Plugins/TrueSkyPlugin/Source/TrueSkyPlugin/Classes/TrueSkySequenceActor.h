#pragma once

#include "TrueSkyComponent.h"
#include "TrueSkySequenceActor.generated.h"


UCLASS(hideCategories=(Actor, Advanced, Display, Events, Object, Attachment, Movement, Collision, Rendering, Input), MinimalAPI, Blueprintable, notplaceable)
class ATrueSkySequenceActor : public AActor
{
	GENERATED_UCLASS_BODY()
	~ATrueSkySequenceActor();
	void Destroyed();
	//UPROPERTY(EditAnywhere, Category=TrueSky)
	//FString LicenceKey;

	UFUNCTION(BlueprintCallable, Category=TrueSky)
	void SetTime( float value );
	
	UFUNCTION(BlueprintCallable, Category=TrueSky)
	float GetFloat(FString name ) const;

	UFUNCTION(BlueprintCallable, Category=TrueSky)
	void SetFloat(FString name, float value );

	UFUNCTION(BlueprintCallable, Category=TrueSky)
	int32 GetInt(FString name ) const;

	UFUNCTION(BlueprintCallable, Category=TrueSky)
	void SetInt(FString name, int32 value );

	UFUNCTION(BlueprintCallable, Category=TrueSky)
	float GetKeyframeFloat(int32 keyframeUid,FString name ) const;

	UFUNCTION(BlueprintCallable, Category=TrueSky)
	void SetKeyframeFloat(int32 keyframeUid,FString name, float value );

	UFUNCTION(BlueprintCallable, Category=TrueSky)
	int32 GetKeyframeInt(int32 keyframeUid,FString name ) const;

	UFUNCTION(BlueprintCallable, Category=TrueSky)
	void SetKeyframeInt(int32 keyframeUid,FString name, int32 value );

	UFUNCTION(BlueprintCallable, Category=TrueSky)
	FRotator GetSunRotation() const;

	UFUNCTION(BlueprintCallable, Category=TrueSky)
	FLinearColor GetSunColor() const;

	UPROPERTY(EditAnywhere, Category=TrueSky)
	class UTrueSkySequenceAsset* ActiveSequence;

	UFUNCTION(BlueprintCallable, Category=TrueSky)
	int32 GetNextModifiableSkyKeyframe() const;
	
	UFUNCTION(BlueprintCallable, Category=TrueSky)
	int32 GetNextModifiableCloudKeyframe(int32 layer) const;

	//UPROPERTY(EditAnywhere, Category=TrueSky)
	//UTextureRenderTarget2D* CloudShadowRenderTarget;

	UPROPERTY(EditAnywhere, Category=TrueSky,meta=(ClampMin = "0.0", ClampMax = "1.0"))
	float SimpleCloudShadowing;

	UPROPERTY(EditAnywhere, Category=TrueSky,meta=(ClampMin = "0.0", ClampMax = "1.0"))
	float SimpleCloudShadowSharpness;

	UPROPERTY(EditAnywhere, Category=TrueSky)
	bool Visible;
	void PostInitProperties() override;
	void PostLoad() override;
	void PostInitializeComponents() override;
	void TickActor( float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction ) override;
#if WITH_EDITOR
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
protected:
	UTrueSkyComponent *trueSkyComponent;
	void TransferProperties();
};
