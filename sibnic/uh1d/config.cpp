class CfgPatches
{
	class HelicopterModSIBUH1D2
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.01;
		requiredAddons[]={"HelicopterModScriptsSIB"};
	};
};
class CfgMods
{
	class HelicopterModSIBUH1D2
	{
		dir="Sibnic/UH1D";
		hideName=0;
		hidePicture=0;
		name="HelicopterModSIBUH1D2";
		credits="";
		author="SIBNIC";
		authorID="";
		version="version 6.03";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			
			
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"sibnic/uh1d/4_World"
				};
			};
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"sibnic/uh1d/3_Game"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"sibnic/uh1d/5_Mission"
				};
			};
		};
	};
};


class CfgSoundShaders
{
	class Heli_UH1D_crash_SoundShaders
	{
		samples[]={{"sibnic\uh1d\Sound\crash",1}};
		range=250;
		volume=1.0;
	};
	class Heli_UH1D_warning_SoundShaders
	{
		samples[]={{"sibnic\uh1d\Sound\warning",1}};
		range=250;
		volume=1.0;
	};
	class Heli_UH1D_engine_SoundShaders1
	{
		samples[]={{"sibnic\uh1d\Sound\engine",1}};
		range=700;
		volume=1.2;
	};
	class Heli_UH1D_rotor_SoundShaders
	{
		samples[]={{"sibnic\uh1d\Sound\rotor",1}};
		range=700;
		volume=1.2;
	};
	class Heli_UH1D_start_SoundShaders
	{
		samples[]={{"sibnic\uh1d\Sound\start",1}};
		range=700;
		volume=1.2;
	};

	class Heli_UH1D_stop_SoundShaders
	{
		samples[]={{"sibnic\uh1d\Sound\stop",1}};
		range=700;
		volume=1.2;
	};
};
class CfgSoundSets
{
	class Heli_base_SoundSet;
	class Helicopter_UH1D_Crash_SoundSets: Heli_base_SoundSet
	{
		soundShaders[]={"Heli_UH1D_crash_SoundShaders"};
	};
	class Helicopter_UH1D_Warning_SoundSets: Heli_base_SoundSet
	{
		soundShaders[]={"Heli_UH1D_warning_SoundShaders"};
	};
	class Helicopter_UH1D_Start_SoundSets: Heli_base_SoundSet
	{
		soundShaders[]={"Heli_UH1D_start_SoundShaders"};
	};
	class Helicopter_UH1D_Stop_SoundSets: Heli_base_SoundSet
	{
		soundShaders[]={"Heli_UH1D_stop_SoundShaders"};
	};
	class Helicopter_UH1D_Engine_SoundSets: Heli_base_SoundSet
	{
		soundShaders[]={"Heli_UH1D_engine_SoundShaders1"};
		loop=1;
	};
	class Helicopter_UH1D_Rotor_SoundSets: Heli_base_SoundSet
	{
		soundShaders[]={"Heli_UH1D_rotor_SoundShaders"};
		loop=1;
	};
};


class CfgVehicles
{
	
	class AnimationSources;
	class CarDoor;
	
	class SIBUH1D_Door_1_1: CarDoor
	{
		scope = 2;
		displayName = "doors_driver";
		descriptionShort = "";
		model = "\sibnic\uh1d\SIBUH1D_doors_driver.p3d";
		inventorySlot[] = {"SIBUH1D_Door_1_1"};
		rotationFlags = 8;
	};
	class SIBUH1D_Door_1_2: CarDoor
	{
		scope = 2;
		displayName = "doors_cargo1";
		descriptionShort = "";
		model = "\sibnic\uh1d\SIBUH1D_doors_cargo1.p3d";
		inventorySlot[] = {"SIBUH1D_Door_1_2"};
		rotationFlags = 8;
	};
	class SIBUH1D_Door_2_1: CarDoor
	{
		scope = 2;
		displayName = "doors_codriver";
		descriptionShort = "";
		model = "\sibnic\uh1d\SIBUH1D_doors_codriver.p3d";
		inventorySlot[] = {"SIBUH1D_Door_2_1"};
		rotationFlags = 8;
	};
	class SIBUH1D_Door_2_2: CarDoor
	{
		scope = 2;
		displayName = "doors_cargo2";
		descriptionShort = "";
		model = "\sibnic\uh1d\SIBUH1D_doors_cargo2.p3d";
		inventorySlot[] = {"SIBUH1D_Door_2_2"};
		rotationFlags = 8;
	};
	
	class HeliSIB_middle;
	class HeliSIB_UH1D_base: HeliSIB_middle
	{
		scope=1;
		model="sibnic\uh1d\UH1D.p3d";
		attachments[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2","SIBUH1D_Door_1_1","SIBUH1D_Door_1_2","SIBUH1D_Door_2_1","SIBUH1D_Door_2_2","CarBattery"};
		class GUIInventoryAttachmentsProps
		{	
			class Engine
			{
				name = "$STR_attachment_Engine0";
				description = "";
				attachmentSlots[] = {"CarBattery"};
				icon = "cat_vehicle_engine";
			};
			class Chassis
			{
				name = "$STR_attachment_Chassis0";
				description = "";
				icon = "cat_vehicle_chassis";
				attachmentSlots[] = {"NivaWheel_1_1","NivaWheel_1_2","NivaWheel_2_1","NivaWheel_2_2"};
			};
			class Body
			{
				name = "$STR_attachment_Body0";
				description = "";
				icon="cat_vehicle_body";
				attachmentSlots[] = {"SIBUH1D_Door_1_1","SIBUH1D_Door_1_2","SIBUH1D_Door_2_1","SIBUH1D_Door_2_2"};
			};
		};
		class AnimationSources:AnimationSources
		{
			class capot
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 8000;
					healthLevels[] = {{1.0,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0.0,{}}};
				};
			};
			class DamageZones
			{
				class Body
				{
					fatalInjuryCoef = 0.001;
					memoryPoints[] = {"dmgzone_body"};
					componentNames[] = {"dmgzone_body"};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0.001;
					};
					transferToZonesNames[] = {};
					inventorySlots[] = {};
				};
				class Chassis
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgzone_chassis"};
					componentNames[] = {"dmgzone_chassis"};
					class Health
					{
						hitpoints = 50000;
						transferToGlobalCoef = 0;

					};
					inventorySlots[] = {};
					inventorySlotsCoefs[] = {};
				};
				class Engine
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgzone_engine"};
					componentNames[] = {"dmgzone_engine"};
					class Health
					{
						hitpoints = 20000;
						transferToGlobalCoef = 0;

					};
					transferToZonesNames[] = {};
					inventorySlots[] = {};
					inventorySlotsCoefs[] = {};
				};
				class Fuel
				{
					fatalInjuryCoef = -1;
					componentNames[] = {"dmgzone_fuel"};
					memoryPoints[] = {"dmgzone_fuel"};
					class Health
					{
						hitpoints = 3700;
						transferToGlobalCoef = 0;

					};
					transferToZonesNames[] = {};
					inventorySlotsCoefs[] = {};
					inventorySlots[] = {};
				};
				class Rotor1
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgzone_rotor1"};
					componentNames[] = {"dmgzone_rotor1"};
					class Health
					{
						hitpoints = 8000;
						transferToGlobalCoef = 0;

					};
					transferToZonesNames[] = {};
					inventorySlots[] = {};
					inventorySlotsCoefs[] = {};
				};
				class Rotor2
				{
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgzone_rotor2"};
					componentNames[] = {"dmgzone_rotor2"};
					class Health
					{
						hitpoints = 8000;
						transferToGlobalCoef = 0;

					};
					transferToZonesNames[] = {};
					inventorySlots[] = {};
					inventorySlotsCoefs[] = {};
				};
				
			};
		};
		
	};
	

	
	class HeliSIB_UH1D: HeliSIB_UH1D_base
	{
		scope=2;
		displayName="UH1D";
		descriptionShort="";
	};
	class HeliSIB_UH1D_clear: HeliSIB_UH1D_base
	{
		scope=2;
		displayName="UH1D";
		descriptionShort="";
	};
	class HeliSIB_UH1H: HeliSIB_UH1D
	{
		scope=2;
		displayName="UH1H";
		descriptionShort="";
	};
	class HeliSIB_UH1H2: HeliSIB_UH1D_clear
	{
		scope=2;
		displayName="UH1H";
		descriptionShort="";
	};
	
};
class CfgSlots
{
	class Slot_SIBUH1D_Door_1_1
	{
		name="SIBUH1D_Door_1_1";
		displayName="Left Door";
		ghostIcon="doorfront";
	};
	class Slot_SIBUH1D_Door_2_1
	{
		name="SIBUH1D_Door_2_1";
		displayName="Right Door";
		ghostIcon="doorfront";
	};
	class Slot_SIBUH1D_Door_1_2
	{
		name="SIBUH1D_Door_1_2";
		displayName="Left Back Door";
		ghostIcon="doorrear";
	};
	class Slot_SIBUH1D_Door_2_2
	{
		name="SIBUH1D_Door_2_2";
		displayName="Right Back Door";
		ghostIcon="doorrear";
	};
	class Slot_SIBUH1D_capot
	{
		name="SIBUH1D_capot";
		displayName="Right Back Door";
		ghostIcon="doorrear";
	};
};

class CfgNonAIVehicles
{
	class ProxyVehiclePart;
	class ProxySIBUH1D_doors_driver: ProxyVehiclePart
	{
		model = "\sibnic\uh1d\SIBUH1D_doors_driver.p3d";
		inventorySlot = "SIBUH1D_Door_1_1";
	};
	class ProxySIBUH1D_doors_codriver: ProxyVehiclePart
	{
		model = "\sibnic\uh1d\SIBUH1D_doors_codriver.p3d";
		inventorySlot = "SIBUH1D_Door_2_1";
	};
	class ProxySIBUH1D_doors_cargo1: ProxyVehiclePart
	{
		model = "\sibnic\uh1d\SIBUH1D_doors_cargo1.p3d";
		inventorySlot = "SIBUH1D_Door_1_2";
	};
	class ProxySIBUH1D_doors_cargo2: ProxyVehiclePart
	{
		model = "\sibnic\uh1d\SIBUH1D_doors_cargo2.p3d";
		inventorySlot = "SIBUH1D_Door_2_2";
	};
	class ProxySIBUH1D_capot: ProxyVehiclePart
	{
		model = "\sibnic\uh1d\SIBUH1D_capot.p3d";
		inventorySlot = "SIBUH1D_capot";
	};
};