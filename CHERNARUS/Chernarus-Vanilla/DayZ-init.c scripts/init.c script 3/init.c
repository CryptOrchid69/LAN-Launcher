void main() {
    //INIT ECONOMY--------------------------------------
    Hive ce = CreateHive();
    if ( ce ) ce.InitOffline();

    //DATE RESET AFTER ECONOMY INIT-------------------------
    int year, month, day, hour, minute;
    int reset_month = 10, reset_day = 15;
    GetGame().GetWorld().GetDate(year, month, day, hour, minute);
    if ((month == reset_month) && (day < reset_day)) {
        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
    } else if ((month == reset_month + 1) && (day > reset_day)) {
        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
    } else if ((month < reset_month) || (month > reset_month + 1)) {
        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
    }
}

class CustomMission: MissionServer {
    override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName) {
        Entity playerEnt;
        playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
        Class.CastTo( m_player, playerEnt );
        GetGame().SelectPlayer( identity, m_player );
        return m_player;
    }

    override void StartingEquipSetup(PlayerBase player, bool clothesChosen) {
        player.RemoveAllItems();
        EntityAI itemEnt;

        // --- CLOTHING ---
        EntityAI jacket = player.GetInventory().CreateInInventory("USMCJacket_Woodland");
        player.GetInventory().CreateInInventory("USMCPants_Woodland");
        player.GetInventory().CreateInInventory("MilitaryBoots_Beige");
        EntityAI helmet = player.GetInventory().CreateInInventory("Mitch2001Helmet");
        player.GetInventory().CreateInInventory("TacticalGloves_Green");
        // Added TacticalGoggles
        player.GetInventory().CreateInInventory("TacticalGoggles"); 

        // --- BACKPACK ---
        EntityAI backpack = player.GetInventory().CreateInInventory("AssaultBag_Ttsko");
        if (backpack) {
            backpack.GetInventory().CreateAttachment("OrienteeringCompass");
            EntityAI gps = backpack.GetInventory().CreateAttachment("GPSReceiver");
            if (gps) gps.GetInventory().CreateInInventory("Battery9V");
            
            // Added 2x AntiChemInjectors
            backpack.GetInventory().CreateInInventory("AntiChemInjector");
            backpack.GetInventory().CreateInInventory("AntiChemInjector");
        }

        // --- HELMET ATTACHMENTS ---
        if (helmet) {
            EntityAI nvg = helmet.GetInventory().CreateAttachment("NVGoggles");
            if (nvg) nvg.GetInventory().CreateInInventory("Battery9V");
        }

        // --- BELT & SHEATH ---
        EntityAI belt = player.GetInventory().CreateInInventory("MilitaryBelt");
        if (belt) {
            EntityAI sheath = belt.GetInventory().CreateAttachment("NylonKnifeSheath");
            if (sheath) sheath.GetInventory().CreateInInventory("CombatKnife");
            belt.GetInventory().CreateInInventory("Canteen");
        }

        // --- PLATE CARRIER SYSTEM ---
        EntityAI vest = player.GetInventory().CreateInInventory("PlateCarrierVest_Woodland");
        EntityAI pouches;
        if (vest) {
            vest.GetInventory().CreateAttachment("PlateCarrierHolster_Woodland");
            pouches = vest.GetInventory().CreateAttachment("PlateCarrierPouches_Woodland");
        }

        // --- WEAPONS ---
        player.GetInventory().CreateInInventory("Mace");
        
        // Primary Weapon: AUG
        EntityAI aug = player.GetInventory().CreateInInventory("Aug");
        if (aug) {
            aug.GetInventory().CreateAttachment("M4_Suppressor");
            aug.GetInventory().CreateAttachment("ACOGOptic");
            aug.GetInventory().CreateAttachment("Mag_STANAG_60Rnd");
        }

        // Sidearm: Deagle
        EntityAI deagle = player.GetInventory().CreateInInventory("Deagle_Gold");
        if (deagle) {
            deagle.GetInventory().CreateAttachment("PistolSuppressor");
            deagle.GetInventory().CreateAttachment("PistolOptic");
        }

        // --- ITEMS IN JACKET ---
        if (jacket) {
            jacket.GetInventory().CreateInInventory("TetracyclineAntibiotics");
            jacket.GetInventory().CreateInInventory("BandageDressing");
            jacket.GetInventory().CreateInInventory("BandageDressing");
            jacket.GetInventory().CreateInInventory("Whetstone");
            jacket.GetInventory().CreateInInventory("Whetstone");
            jacket.GetInventory().CreateInInventory("CrabCan");
            jacket.GetInventory().CreateInInventory("CrabCan");
            jacket.GetInventory().CreateInInventory("CrabCan");
            jacket.GetInventory().CreateInInventory("CrabCan");
            jacket.GetInventory().CreateInInventory("FilteringBottle");
            jacket.GetInventory().CreateInInventory("Candycane_Red");
            jacket.GetInventory().CreateInInventory("Kvass");
            jacket.GetInventory().CreateInInventory("Kvass");
        }

        // --- ITEMS IN POUCHES ---
        if (pouches) {
            // 300 rounds .357 (Stacked as 100 per slot)
            pouches.GetInventory().CreateInInventory("Ammo_357");
            pouches.GetInventory().CreateInInventory("Ammo_357");
            pouches.GetInventory().CreateInInventory("Ammo_357");
            
            // 300 rounds 5.56x45Tracer (Stacked as 60 per slot)
            for (int i = 0; i < 5; i++) {
                pouches.GetInventory().CreateInInventory("Ammo_556x45Tracer");
            }
        }
    }
};

Mission CreateCustomMission(string path) {
    return new CustomMission();
}