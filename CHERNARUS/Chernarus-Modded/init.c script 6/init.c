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
        EntityAI sweater = player.GetInventory().CreateInInventory("MilitarySweater_Chernarus");
        EntityAI pants = player.GetInventory().CreateInInventory("HunterPants_Spring");
        player.GetInventory().CreateInInventory("WorkingBoots_Green");
        player.GetInventory().CreateInInventory("WoolGlovesFingerless_Green");

        // Tactical Goggles
        player.GetInventory().CreateInInventory("TacticalGoggles");

        // --- DUFFELBAG ---
        EntityAI backpack = player.GetInventory().CreateInInventory("DuffelBagSmall_Camo");
        if (backpack)
        {
            backpack.GetInventory().CreateInInventory("Compass");

            EntityAI gps = backpack.GetInventory().CreateInInventory("GPSReceiver");
            if (gps)
            {
                gps.GetInventory().CreateAttachment("Battery9V");
            }
            
            backpack.GetInventory().CreateInInventory("PipeWrench");
        }

        // --- WEAPONS ---
        player.GetInventory().CreateInInventory("LongWoodenStick");

        // --- ITEMS IN MilitarySweater_Chernarus ---
        if (sweater)
        {
            sweater.GetInventory().CreateInInventory("BandageDressing");
            sweater.GetInventory().CreateInInventory("ChernarusMap");
            sweater.GetInventory().CreateInInventory("BoneKnife");
            sweater.GetInventory().CreateInInventory("SmallStone");
            sweater.GetInventory().CreateInInventory("SmallStone");
            sweater.GetInventory().CreateInInventory("BoletusMushroom");
            sweater.GetInventory().CreateInInventory("SodaCan_Kvass");
        }
    }
};

Mission CreateCustomMission(string path)
{
    return new CustomMission();
}
