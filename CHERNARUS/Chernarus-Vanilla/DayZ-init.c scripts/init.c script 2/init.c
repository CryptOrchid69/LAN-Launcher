void main()
{
    //INIT ECONOMY--------------------------------------
    Hive ce = CreateHive();
    if ( ce )
        ce.InitOffline();

    //DATE RESET AFTER ECONOMY INIT-------------------------
    int year, month, day, hour, minute;
    int reset_month = 10, reset_day = 15;
    GetGame().GetWorld().GetDate(year, month, day, hour, minute);

    if ((month == reset_month) && (day < reset_day))
    {
        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
    }
    else
    {
        if ((month == reset_month + 1) && (day > reset_day))
        {
            GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
        }
        else
        {
            if ((month < reset_month) || (month > reset_month + 1))
            {
                GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
            }
        }
    }
}

class CustomMission: MissionServer
{
    override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
    {
        Entity playerEnt;
        playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
        Class.CastTo( m_player, playerEnt );
        GetGame().SelectPlayer( identity, m_player );

        return m_player;
    }

    override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
    {
        // Remove default clothes
        player.RemoveAllItems();

        EntityAI itemEnt;
        ItemBase itemBs;

        // --- CLOTHING ---
        itemEnt = player.GetInventory().CreateInInventory("WoolCoat_Black");
        EntityAI coat = itemEnt;

        itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
        itemEnt = player.GetInventory().CreateInInventory("HikingBootsLow_Black");
        itemEnt = player.GetInventory().CreateInInventory("SherpaHat_Black");
        itemEnt = player.GetInventory().CreateInInventory("WoolGlovesFingerless_Black");
        itemEnt = player.GetInventory().CreateInInventory("DryBag_Black");

        // --- EYEWEAR ---
        itemEnt = player.GetInventory().CreateInInventory("TacticalGoggles");

        // --- BELT & SHEATH ---
        itemEnt = player.GetInventory().CreateInInventory("CivilianBelt");
        EntityAI sheath = itemEnt.GetInventory().CreateAttachment("NylonKnifeSheath");
        sheath.GetInventory().CreateInInventory("HuntingKnife");

        // --- PLATE CARRIER SYSTEM ---
        itemEnt = player.GetInventory().CreateInInventory("PlateCarrierVest_Black");
        EntityAI vest = itemEnt;
        vest.GetInventory().CreateAttachment("PlateCarrierHolster_Black");
        EntityAI pouches = vest.GetInventory().CreateAttachment("PlateCarrierPouches_Black");

        // --- WEAPONS (Shoulder) ---
        player.GetInventory().CreateInInventory("Mace");
        player.GetInventory().CreateInInventory("WoodAxe");

        // --- DEAGLE (In Inventory/Holster) ---
        itemEnt = player.GetInventory().CreateInInventory("Deagle_Gold");
        itemEnt.GetInventory().CreateAttachment("PistolSuppressor");
        itemEnt.GetInventory().CreateAttachment("PistolOptic");

        // --- ITEMS IN WOOL COAT ---
        if (coat)
        {
            coat.GetInventory().CreateInInventory("TetracyclineAntibiotics");
            coat.GetInventory().CreateInInventory("BandageDressing");
            coat.GetInventory().CreateInInventory("BandageDressing");
            coat.GetInventory().CreateInInventory("Whetstone");
            coat.GetInventory().CreateInInventory("Whetstone");
            coat.GetInventory().CreateInInventory("CrabCan");
            coat.GetInventory().CreateInInventory("CrabCan");
            coat.GetInventory().CreateInInventory("CrabCan");
            coat.GetInventory().CreateInInventory("CrabCan");
            coat.GetInventory().CreateInInventory("FilteringBottle");
            coat.GetInventory().CreateInInventory("Candycane_Red");
            coat.GetInventory().CreateInInventory("Kvass");
            coat.GetInventory().CreateInInventory("Kvass");
        }

        // --- ITEMS IN POUCHES ---
        if (pouches)
        {
            pouches.GetInventory().CreateInInventory("Mag_Deagle_9rnd");
            pouches.GetInventory().CreateInInventory("Mag_Deagle_9rnd");
            pouches.GetInventory().CreateInInventory("Mag_Deagle_9rnd");

            // 540 rounds of .357 (9 boxes of 20 - DayZ handles stack limits automatically)
            for (int i = 0; i < 27; i++)
            {
                pouches.GetInventory().CreateInInventory("Ammo_357");
            }
        }
    }
};

Mission CreateCustomMission(string path)
{
    return new CustomMission();
}