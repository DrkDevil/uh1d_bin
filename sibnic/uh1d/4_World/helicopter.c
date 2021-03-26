

class SIBUH1D_Door_1_1 extends CarDoor {};
class SIBUH1D_Door_1_2 extends CarDoor {};
class SIBUH1D_Door_2_1 extends CarDoor {};
class SIBUH1D_Door_2_2 extends CarDoor {};


class HeliSIB_UH1D_base extends HeliSIB_big
{
	override void EEInit()
	{
		super.EEInit();
		c_startSound = "Helicopter_UH1D_Start_SoundSets";
		c_stopSound = "Helicopter_UH1D_Stop_SoundSets";
		c_rotorSound = "Helicopter_UH1D_Rotor_SoundSets";
		c_engineSound = "Helicopter_UH1D_Engine_SoundSets";
		c_warningSound = "Helicopter_UH1D_Warning_SoundSets";
		c_crashSound = "Helicopter_UH1D_Crash_SoundSets";
		c_fuelDistance = 3.2;
	}
	
	override void creat_InInventory_heli()
	{
		
		if(IsKindOf("HeliSIB_UH1D"))
		{
			GetInventory().CreateInInventory( "SIBUH1D_Door_1_1" );
			GetInventory().CreateInInventory( "SIBUH1D_Door_1_2" );
			GetInventory().CreateInInventory( "SIBUH1D_Door_2_1" );
			GetInventory().CreateInInventory( "SIBUH1D_Door_2_2" );
			GetInventory().CreateInInventory( "SIBUH1D_capot" );
			GetInventory().CreateInInventory( "CarBattery" );
			return;
		}
		
		super.creat_InInventory_heli();
	};

	override string GetDoorInvSlotNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "SIBUH1D_Door_1_1";
			break;
		case 1:
			return "SIBUH1D_Door_2_1";
			break;
		case 2:
			return "SIBUH1D_Door_1_2";
			break;
		case 3:
			return "SIBUH1D_Door_2_2";
			break;
		}
		
		return super.GetDoorInvSlotNameFromSeatPos(posIdx);
	}
	


	override int GetCarDoorsState( string slotType )
	{
		CarDoor carDoor;

		Class.CastTo( carDoor, FindAttachmentBySlotName( slotType ) );
		if ( !carDoor )return CarDoorState.DOORS_MISSING;
		
		switch( slotType )
		{
		case "SIBUH1D_Door_1_1":
			if ( GetAnimationPhase("DoorsDriver") > 0.1 )
			return CarDoorState.DOORS_OPEN;
			else
			return CarDoorState.DOORS_CLOSED;

			break;
			
		case "SIBUH1D_Door_2_1":
			if ( GetAnimationPhase("DoorsCoDriver") > 0.1 )
			return CarDoorState.DOORS_OPEN;
			else
			return CarDoorState.DOORS_CLOSED;

			break;
			
		case "SIBUH1D_Door_1_2":
			if ( GetAnimationPhase("DoorsCargo1") > 0.1 )
			return CarDoorState.DOORS_OPEN;
			else
			return CarDoorState.DOORS_CLOSED;

			break;
			
		case "SIBUH1D_Door_2_2":
			if ( GetAnimationPhase("DoorsCargo2") > 0.1 )
			return CarDoorState.DOORS_OPEN;
			else
			return CarDoorState.DOORS_CLOSED;
			break;
		case "SIBUH1D_capot":
				if ( GetAnimationPhase("capot") > 0.1 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
		}

		return CarDoorState.DOORS_MISSING;
	}
	
	override string GetAnimSourceFromSelection( string selection )
	{
		switch( selection )
		{
		case "doors_driver":
			return "DoorsDriver";
		case "doors_codriver":
			return "DoorsCoDriver";
		case "doors_cargo1":
			return "DoorsCargo1";
		case "doors_cargo2":
			return "DoorsCargo2";
		case "doors_hood":
			return "DoorsHood";
		case "doors_trunk":
			return "DoorsTrunk";
		/*case "capot":
			return "capot";*/
		}

		return "";
	}

	

	override bool CrewCanGetThrough( int posIdx )
	{
		switch( posIdx )
		{
		case 0:
			if ( GetCarDoorsState( "SIBUH1D_Door_1_1" ) == CarDoorState.DOORS_CLOSED )
			return false;

			return true;
			break;
			
		case 1:
			if ( GetCarDoorsState( "SIBUH1D_Door_2_1" ) == CarDoorState.DOORS_CLOSED )
			return false;

			return true;
			break;

		case 2:
			if ( GetCarDoorsState( "SIBUH1D_Door_1_2" ) == CarDoorState.DOORS_CLOSED )
			return false;

			return true;
			break;

		case 3:
			if ( GetCarDoorsState( "SIBUH1D_Door_2_2" ) == CarDoorState.DOORS_CLOSED )
			return false;

			return true;
			break;
		}

		return false;
	}
	override bool CanDisplayAttachmentCategory( string category_name )
	{

		if(category_name == "Chassis")return false;
		
		/*if(category_name == "Engine")
		{
			if ( GetCarDoorsState("SIBUH1D_capot") == CarDoorState.DOORS_CLOSED )
				return false;
		}*/
				
		return true;
	}
	override bool CanReleaseAttachment( EntityAI attachment )
	{
		string attType = attachment.GetType();
		if ( attType == "HatchbackWheel" )
        return false;

		return true;
	}
	override bool IsVitalTruckBattery()
	{
		return true;
	}
};
class HeliSIB_UH1D extends HeliSIB_UH1D_base{};
class HeliSIB_UH1D2 extends HeliSIB_UH1D_base{};

modded class ActionHeliStartEngineSIB
{

	override void StartEngineSIB(HeliTest_SIB heli)
	{
		if(heli.IsKindOf("HeliSIB_UH1D_base"))
		{
			EntityAI battery = heli.GetInventory().FindAttachment(InventorySlots.GetSlotIdFromString("CarBattery"));
			if ( !battery || battery && battery.IsRuined() )
			{
				return;
			}
		}
		super.StartEngineSIB(heli);
	};
};


