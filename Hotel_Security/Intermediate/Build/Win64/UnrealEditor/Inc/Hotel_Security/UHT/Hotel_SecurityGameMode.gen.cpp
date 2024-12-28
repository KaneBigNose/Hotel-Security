// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Hotel_Security/Hotel_SecurityGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHotel_SecurityGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	HOTEL_SECURITY_API UClass* Z_Construct_UClass_AHotel_SecurityGameMode();
	HOTEL_SECURITY_API UClass* Z_Construct_UClass_AHotel_SecurityGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Hotel_Security();
// End Cross Module References
	void AHotel_SecurityGameMode::StaticRegisterNativesAHotel_SecurityGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHotel_SecurityGameMode);
	UClass* Z_Construct_UClass_AHotel_SecurityGameMode_NoRegister()
	{
		return AHotel_SecurityGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AHotel_SecurityGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHotel_SecurityGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Hotel_Security,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHotel_SecurityGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHotel_SecurityGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Hotel_SecurityGameMode.h" },
		{ "ModuleRelativePath", "Hotel_SecurityGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHotel_SecurityGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHotel_SecurityGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AHotel_SecurityGameMode_Statics::ClassParams = {
		&AHotel_SecurityGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHotel_SecurityGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AHotel_SecurityGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AHotel_SecurityGameMode()
	{
		if (!Z_Registration_Info_UClass_AHotel_SecurityGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHotel_SecurityGameMode.OuterSingleton, Z_Construct_UClass_AHotel_SecurityGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AHotel_SecurityGameMode.OuterSingleton;
	}
	template<> HOTEL_SECURITY_API UClass* StaticClass<AHotel_SecurityGameMode>()
	{
		return AHotel_SecurityGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHotel_SecurityGameMode);
	AHotel_SecurityGameMode::~AHotel_SecurityGameMode() {}
	struct Z_CompiledInDeferFile_FID_Hotel_Security_Hotel_Security_Source_Hotel_Security_Hotel_SecurityGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Hotel_Security_Hotel_Security_Source_Hotel_Security_Hotel_SecurityGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AHotel_SecurityGameMode, AHotel_SecurityGameMode::StaticClass, TEXT("AHotel_SecurityGameMode"), &Z_Registration_Info_UClass_AHotel_SecurityGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHotel_SecurityGameMode), 3067167544U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Hotel_Security_Hotel_Security_Source_Hotel_Security_Hotel_SecurityGameMode_h_923519302(TEXT("/Script/Hotel_Security"),
		Z_CompiledInDeferFile_FID_Hotel_Security_Hotel_Security_Source_Hotel_Security_Hotel_SecurityGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Hotel_Security_Hotel_Security_Source_Hotel_Security_Hotel_SecurityGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
