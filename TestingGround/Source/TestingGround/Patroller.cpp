// Fill out your copyright notice in the Description page of Project Settings.

#include "Patroller.h"


TArray<AActor*> UPatroller::GetPatrolPoints() const
{
	return Waypoints;
}

