void main()
{
    // INIT ECONOMY--------------------------------------
    Hive ce = CreateHive();
    if (ce)
        ce.InitOffline();

    // DATE RESET AFTER ECONOMY INIT----------------------
    int year, month, day, hour, minute;
    int reset_month = 10;
    int reset_day = 15;

    GetGame().GetWorld().GetDate(year, month, day, hour, minute);

    if ((month == reset_month) && (day < reset_day))
    {
        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
    }
    else if ((month == reset_month + 1) && (day > reset_day))
    {
        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
    }
    else if ((month < reset_month) || (month > reset_month + 1))
    {
        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
    }
}

class CustomMission : MissionServer
{
    override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
    {
        Entity playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
        Class.CastTo(m_player, playerEnt);

        GetGame().SelectPlayer(identity, m_player);
        return m_player;
    }

    override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
    {
        player.RemoveAllItems();

        // --- CLOTHING ---
        EntityAI jacket = player.GetInventory().CreateInInventory("TracksuitJacket_Black");
        player.GetInventory().CreateInInventory("TracksuitPants_Black");
        player.GetInventory().CreateInInventory("HikingBootsLow_Black");
        player.GetInventory().CreateInInventory("SherpaHat_Black");
        player.GetInventory().CreateInInventory("WoolGlovesFingerless_Black");

        // Tactical Goggles
        player.GetInventory().CreateInInventory("TacticalGoggles");

        // --- DUFFELBAG ---
        EntityAI backpack = player.GetInventory().CreateInInventory("DuffelBagSmall_Camo");
        if (backpack)
        {
            backpack.GetInventory().CreateAttachment("Compass");

            EntityAI gps = backpack.GetInventory().CreateAttachment("GPSReceiver");
            if (gps)
            {
                gps.GetInventory().CreateInInventory("Battery9V");
            }
        }

        // --- BELT & SHEATH ---
        EntityAI belt = player.GetInventory().CreateInInventory("CivilianBelt");
        if (belt)
        {
            EntityAI sheath = belt.GetInventory().CreateAttachment("NylonKnifeSheath");
            if (sheath)
            {
                sheath.GetInventory().CreateInInventory("HuntingKnife");
            }

            belt.GetInventory().CreateInInventory("FilteringBottle");
        }

        // --- WEAPONS ---
        player.GetInventory().CreateInInventory("Mace");

        // --- ITEMS IN JACKET ---
        if (jacket)
        {
            jacket.GetInventory().CreateInInventory("BandageDressing");
            jacket.GetInventory().CreateInInventory("Whetstone");
            jacket.GetInventory().CreateInInventory("CrabCan");
            jacket.GetInventory().CreateInInventory("Kvass");
            jacket.GetInventory().CreateInInventory("ChernarusMap");
            jacket.GetInventory().CreateInInventory("MatchBox");
        }
    }
};

Mission CreateCustomMission(string path)
{
    return new CustomMission();
}