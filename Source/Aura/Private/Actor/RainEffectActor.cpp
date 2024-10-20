// Copyright Rain


#include "Actor/RainEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/RainAttributeSet.h"
#include "Components/SphereComponent.h"

// Sets default values
ARainEffectActor::ARainEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void ARainEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent,
									AActor* OtherActor,
									UPrimitiveComponent* OtherComp,
									int32 OtherBodyIndex,
									bool bFromSweep,
									const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ASCIntrface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const URainAttributeSet* AttributeSet = Cast<URainAttributeSet>(ASCIntrface->GetAbilitySystemComponent()->GetAttributeSet(URainAttributeSet::StaticClass()));
		
		URainAttributeSet* MutableRainAttributeSet = const_cast<URainAttributeSet*>(AttributeSet);

		MutableRainAttributeSet->SetHealth(AttributeSet->GetHealth() + 25.0f);
		MutableRainAttributeSet->SetMana(AttributeSet->GetMana() - 25.0f);
		Destroy();
	}
}

void ARainEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent,
									AActor* OtherActor,
									UPrimitiveComponent* OtherComp,
									int32 OtherBodyIndex)
{

}

void ARainEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ARainEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ARainEffectActor::EndOverlap);
}