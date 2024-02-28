// Fill out your copyright notice in the Description page of Project Settings.

#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (Tank)
    {
        // Find tank location and distance
        float Distance = FVector::Dist(Tank->GetActorLocation(), GetActorLocation());

        // Check if within range
        if (Distance <= FireRange)
        {
            // Rotate toward tank if within range
            RotateTurret(Tank->GetActorLocation());
        }
    }
}

void ATower::BeginPlay()
{
    Super::BeginPlay();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}