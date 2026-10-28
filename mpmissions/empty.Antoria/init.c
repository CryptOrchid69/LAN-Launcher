#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\BunkerHelperClasses.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\BunkerCreator.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\BaseLayout.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\BunkerAIZone.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Preset_Atrium.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_CustomGrid20x20.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_CustomGrid20x19.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_CustomGrid11x12.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_CustomGrid22x27.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_Plus12Rooms_25x25.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_CustomGridCustom1.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_CustomGrid41x41.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_SmallBunker_1.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_SmallBunker_2.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_MediumBunker_1.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_MediumBunker_2.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_LargeBunker_1.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_LargeBunker_2.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_2FloorMazeBunker.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_OpenAreaBunker.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_11x11_3xFullGearRooms.c"
#include "$CurrentDir:\\mpmissions\\empty.Antoria\\Bunker_Layouts\\Layout_ModularTest.c"


static ref BunkerAIZone g_FP_BunkerZone;

void SpawnObject(string objectName, vector position, vector orientation)
{
        Object obj = Object.Cast(GetGame().CreateObject(objectName, "0 0 0"));

        if (!obj)
        {
                Print("[ANTORIA INIT] SpawnObject FAILED - missing/invalid classname: " + objectName + " pos=" + position.ToString() + " ori=" + orientation.ToString());
                return;
        }

        obj.SetPosition(position);
        obj.SetOrientation(orientation);

        // Force update collisions/pathgraph only when the spawned object supports it.
        if (obj.CanAffectPathgraph())
        {
                obj.SetAffectPathgraph(true, false);
                GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, obj);
        }
}

void main() {
        //INIT WEATHER BEFORE ECONOMY INIT------------------------
        //Weather weather = g_Game.GetWeather();
        //weather.MissionWeather(false);    // false = use weather controller from Weather.c
        //weather.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
        //weather.GetRain().Set( 0, 0, 1);
        //weather.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);
        // SPAWN CUSTOM BUILDINGS FROM SKAERHEIM.TXT
      SpawnObject( "di_abandoned_warehouse", "19715.300781 70.982903 839.489014", "0.656780 0.000000 -0.000000" );
     
      //// -- Shatwest_Latina.txt (6 objects)
      SpawnObject("Land_shatwest_signage", "17550.599609 155.033005 4154.089844", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_shatwest_signage", "17541.800781 153.492004 4155.689941", "89.104713 0.000000 -0.000000");
      SpawnObject("Land_shatwest_signage", "17041.900391 154.369003 4031.169922", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_shatwest_signage", "17025.599609 154.326004 4037.550049", "90.000000 0.000000 -0.000000");
      SpawnObject("Land_shatwest_signage", "17035.199219 154.039993 4048.620117", "89.366951 0.000000 -0.000000");
      SpawnObject("Land_shatwest_signage", "17550.599609 153.759003 4160.439941", "0.000000 0.000000 -0.000000");
      //// -- ROAD BARRICADE BYPASS TILSLEY.txt (19 objects)
      SpawnObject("StaticObj_Ruin_Rubble", "17849.300781 76.405899 1899.260010", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Hotel_Damaged_Rubble", "17848.800781 69.673500 1902.089966", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_rubble_bricks3", "17855.699219 75.498100 1897.219971", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_rubble_dirtpile_large", "17853.300781 77.166797 1903.449951", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_rubble_dirtpile_medium1", "17850.500000 77.108000 1907.930054", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_rubble_dirtpile_medium2", "17849.599609 76.792900 1904.479980", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_rubble_metal2", "17852.599609 77.691002 1901.479980", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_rubble_rocks1", "17885.400391 71.745102 1868.910034", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_rubble_rocks2", "17875.599609 71.754601 1867.130005", "75.723320 0.000000 -0.000000");
      SpawnObject("ANT_rubble_wood1", "17872.500000 73.333504 1875.369995", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_rubble_wood2", "17873.300781 72.532700 1871.719971", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_rubble_wood3", "17871.699219 73.702904 1870.479980", "0.000000 5.000141 0.000000");
      SpawnObject("ANT_ruin_rubble", "17882.400391 72.474197 1479.619995", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_rubble_dirtpile_large", "17878.000000 73.091496 1878.800049", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Bricks1", "17877.900391 71.737503 1875.130005", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Bricks2", "17876.000000 70.717102 1863.849976", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Bricks1", "17873.800781 70.355399 1862.709961", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_wreck_bulldozer", "17851.000000 77.129402 1892.050049", "0.000000 6.001426 6.001426");
      SpawnObject("ANT_wreck_digger", "17874.199219 76.512299 1878.650024", "16.999998 -5.000000 4.000000");
      //// -- racetrack.txt (24 objects)
      SpawnObject("Land_groggs_signage", "19066.300781 25.879299 8680.299805", "-179.485916 0.000000 -0.000000");
      SpawnObject("Land_groggs_signage2", "19074.199219 25.877899 8680.320313", "-179.202637 0.000000 -0.000000");
      SpawnObject("Land_chickenslut_signage", "19132.900391 25.878099 8679.799805", "-179.104706 0.000000 -0.000000");
      SpawnObject("Land_chickenslut_signage", "19140.800781 25.899200 8679.719727", "-179.300552 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_down", "19160.099609 26.866800 8676.750000", "8.257126 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_down", "19161.199219 26.887600 8676.780273", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_down", "19156.400391 27.038300 8676.969727", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_torycarvery_signage", "19161.699219 27.525000 8676.769531", "179.300552 0.000000 -0.000000");
      SpawnObject("Land_flip_watchtower", "19213.500000 49.988899 8396.650391", "3.282034 0.000000 -0.000000");
      SpawnObject("Land_Radio_PanelPAS", "19215.099609 53.420502 8396.500000", "3.282034 0.000000 -0.000000");
      SpawnObject("Land_flip_watchtower", "19136.699219 46.490898 8389.139648", "1.783787 0.000000 -0.000000");
      SpawnObject("Land_chickenslut_signage", "19390.599609 25.869801 8475.839844", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_chickenslut_signage", "19390.599609 25.851500 8467.889648", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_groggs_signage", "19390.500000 25.882799 8409.139648", "-89.366951 0.000000 0.000000");
      SpawnObject("Land_groggs_signage2", "19390.500000 25.876600 8401.219727", "-91.096420 0.000000 -0.000000");
      SpawnObject("Land_Misc_DeerStand1", "19216.099609 47.049801 8408.730469", "-179.011673 0.000000 -0.000000");
      SpawnObject( "StaticObj_Tank_Medium", "19633.500000 71.989998 885.028992", "0.000000 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Tank_Small_Gas", "19640.099609 71.895203 885.020996", "89.366951 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Tisy_AirShaft", "19643.199219 73.464699 884.401978", "179.580338 0.000000 -0.000000" );
      SpawnObject( "Sewer_Drain_Junction_Platform_Door_Connection", "19644.800781 71.167198 884.414001", "-91.096420 0.000000 -0.000000" );
      SpawnObject( "Land_vlad_wirebox", "19650.099609 71.679703 886.284973", "-0.563035 0.000000 0.000000" );
      SpawnObject( "land_vlad_gas_station", "19635.099609 73.519302 863.031982", "-0.099595 0.000000 -0.000000" );
      SpawnObject( "StaticObj_FueldStation_Feed_NoFuel", "19631.500000 71.252403 862.846008", "-0.099595 0.000000 -0.000000" );
      SpawnObject( "StaticObj_FueldStation_Feed_NoFuel", "19641.099609 71.259499 862.666016", "-0.099595 0.000000 -0.000000" );
      SpawnObject( "ANT_fuelstation_feed", "19631.500000 72.082001 857.857971", "-0.099595 0.000000 -0.000000" );
      SpawnObject( "ANT_fuelstation_feed", "19641.099609 72.053001 857.877014", "-0.099595 0.000000 -0.000000" );
      //// -- notto_latina.txt (5 objects)
      SpawnObject("ANT_wooden_planks_down", "17512.300781 153.496994 4285.250000", "50.289913 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_down", "17512.400391 153.490005 4285.319824", "50.383057 0.000000 -0.000000");
      SpawnObject("Land_notto_signage", "17509.699219 155.298996 4283.970215", "72.998840 0.000000 -0.000000");
      SpawnObject("Land_notto_signage", "17511.599609 155.429993 4289.009766", "140.547577 0.000000 -0.000000");
      SpawnObject("Land_notto_signage", "17528.099609 155.404999 4302.709961", "140.361649 0.000000 -0.000000");
      //// -- nasper-special climbover.txt (2 objects)
      SpawnObject("Land_Castle_Stairs", "9603.889648 165.108002 3247.949951", "107.427269 0.000000 -0.000000");
      SpawnObject("Land_Castle_Stairs", "9600.389648 165.024002 3235.580078", "14.730431 0.000000 -0.000000");
      //// -- nasper high street 1.txt (19 objects)
      SpawnObject("Land_ladsbroke_signage", "9203.570313 153.766006 2723.760010", "179.951035 0.000000 -0.000000");
      SpawnObject("Land_poots_signage", "9233.820313 153.522995 2723.689941", "179.769196 0.000000 -0.000000");
      SpawnObject("Land_wtfsmith_signage", "9278.450195 153.276993 2723.649902", "179.856613 0.000000 -0.000000");
      SpawnObject("Land_hti_signage", "9338.860352 153.501999 2737.790039", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_up", "9137.150391 152.278000 2747.689941", "88.733902 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_up", "9137.110352 152.313004 2747.629883", "89.104713 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "9137.150391 154.028000 2747.689941", "-90.633041 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "9136.679688 155.565994 2744.320068", "-0.657461 0.000000 0.000000");
      SpawnObject("Land_tosco_signage", "9114.080078 155.475006 2744.050049", "-1.031687 0.000000 0.000000");
      SpawnObject("Land_argod_signage", "9451.919922 153.233002 2556.979980", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_poondland_signage", "9451.889648 153.841003 2573.790039", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_shatwest_signage", "9513.120117 152.710999 2662.600098", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_shatwest_signage", "9511.950195 159.983994 2653.639893", "-0.188841 0.000000 0.000000");
      SpawnObject("Land_torycarvery_signage", "9451.870117 153.822006 2682.209961", "-44.565258 0.000000 0.000000");
      SpawnObject("Land_pissitsmonday_signage", "9430.040039 153.419998 2680.979980", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_notto_signage", "9400.769531 153.382004 2681.020020", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_groggs_signage2", "9612.750000 153.490005 2561.830078", "0.657461 0.000000 -0.000000");
      SpawnObject("Land_chickenslut_signage", "9619.450195 153.490005 2561.780029", "0.563035 0.000000 -0.000000");
      SpawnObject("Land_specsavedya_signage", "9740.080078 153.322998 2618.459961", "90.000000 0.000000 -0.000000");

      //// -- MAIN ROAD ACCESSORIES.txt (9 objects)
      SpawnObject("ANT_sign_attention", "4796.509766 216.666000 6487.810059", "-30.774311 0.000000 0.000000");
      SpawnObject("ANT_sign_attention", "4779.000000 223.018997 6724.890137", "175.918976 0.000000 -0.000000");
      SpawnObject("ANT_sign_attention", "4791.709961 215.018005 6058.149902", "67.174690 0.000000 -0.000000");
      SpawnObject("ANT_sign_attention", "4850.189941 215.524002 6192.160156", "154.152710 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Concrete1", "4940.689941 213.727997 6821.660156", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Concrete2", "4942.250000 211.865997 6823.890137", "0.000000 -3.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Concrete1", "4892.470215 226.091995 6781.259766", "179.861984 0.000000 -4.999999");
      SpawnObject("StaticObj_Rubble_DirtPile_Large", "4897.259766 224.363998 6780.919922", "10.853988 -3.000000 15.999994");
      SpawnObject("StaticObj_Rubble_Concrete1", "4894.959961 224.197998 6783.970215", "0.000000 0.000000 -0.000000");
      //// -- lowridge.txt (2 objects)
      SpawnObject("Land_City_Stand_Grocery", "4431.270020 210.160004 4785.250000", "33.589260 0.000000 -0.000000");
      SpawnObject("Land_groggs_signage2", "4428.979980 211.878006 4781.680176", "33.776894 0.000000 -0.000000");
      //// -- hydro well.txt (1 objects)
      SpawnObject("Land_Misc_Well_Pump_Blue", "3362.159912 10.323700 3706.030029", "81.522835 0.000000 -0.000000");
      //// -- hydro east.txt (5 objects)
      SpawnObject("Land_chickenslut_signage", "3964.030029 14.407100 3661.000000", "-38.000008 0.000000 0.000000");
      SpawnObject("Land_groggs_signage2", "3953.179932 14.396400 3652.600098", "-38.373741 0.000000 0.000000");
      SpawnObject("Land_torycarvery_signage", "3958.479980 13.936100 3657.139893", "-38.093262 0.000000 0.000000");
      SpawnObject("ANT_wooden_planks_up", "3980.060059 12.655600 3639.300049", "52.072231 0.000000 -0.000000");
      SpawnObject("Land_notto_signage", "3979.969971 14.621000 3639.300049", "52.354084 0.000000 -0.000000");
      //// -- highrise entry nasper.txt (6 objects)
      SpawnObject("StaticObj_Power_Pole_Wood6_H", "9596.139648 208.716003 3240.070068", "74.664505 -78.000443 0.020732");
      SpawnObject("StaticObj_Power_Pole_Wood6_H", "9596.790039 208.701004 3241.370117", "-99.456146 78.000481 0.006218");
      SpawnObject("StaticObj_Power_Pole_Wood5_rus", "9595.660156 208.455994 3240.649902", "-101.380142 75.995232 179.901138");
      SpawnObject("StaticObj_Rubble_DirtPile_Medium2", "9591.769531 207.796005 3239.449951", "93.798904 0.000000 -0.000000");
      SpawnObject("ANT_castle_stairs", "9530.040039 166.925995 3320.320068", "-177.417740 0.000000 -0.000000");
      SpawnObject("ANT_castle_stairs", "9512.639648 173.067001 3321.159912", "15.199542 0.000000 -0.000000");
      //// -- groggs_vladton.txt (8 objects)
      SpawnObject("Land_groggs_signage", "17686.000000 34.473499 8550.980469", "-44.095932 0.000000 0.000000");
      SpawnObject("Land_poots_signage", "17976.900391 25.708000 8297.440430", "-89.977905 0.000000 -0.000000");
      SpawnObject("Land_poondland_signage", "17976.800781 25.860901 8260.519531", "-89.977364 0.000000 -0.000000");
      SpawnObject("Land_argod_signage", "17976.699219 25.894699 8251.900391", "-90.634560 0.000000 -0.000000");
      SpawnObject("Land_shatwest_signage", "17991.800781 26.265600 8199.089844", "89.039574 0.000000 -0.000000");
      SpawnObject("Land_ladsbroke_signage", "17740.000000 25.831301 7995.669922", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_groggs_signage2", "17801.900391 25.533600 7984.430176", "-179.575806 0.000000 -0.000000");
      SpawnObject("Land_notto_signage", "17580.500000 36.045799 8386.660156", "134.543579 0.000000 -0.000000");
      //// -- groggs_upper_rosco.txt (1 objects)
      SpawnObject("Land_groggs_signage", "12925.500000 153.628998 6382.479980", "44.472939 0.000000 -0.000000");
      //// -- groggs_tinside.txt (8 objects)
      SpawnObject("Land_groggs_signage", "5113.430176 153.233002 1904.939941", "162.502792 0.000000 -0.000000");
      SpawnObject("Land_ladsbroke_signage", "5094.750000 153.205002 1935.750000", "-108.928719 0.000000 -0.000000");
      SpawnObject("Land_specsavedya_signage", "5086.290039 152.694000 1896.390015", "162.689697 0.000000 -0.000000");
      SpawnObject("Land_argod_signage", "5071.029785 152.699005 1891.469971", "162.315689 0.000000 -0.000000");
      SpawnObject("Land_shatwest_signage", "5057.930176 152.792007 1903.489990", "-17.732021 0.000000 0.000000");
      SpawnObject("Land_poondland_signage", "5043.620117 153.063995 1883.060059", "162.499130 0.000000 -0.000000");
      SpawnObject("Land_wtfsmith_signage", "5140.830078 152.807007 1913.380005", "162.128403 0.000000 -0.000000");
      SpawnObject("Land_hti_signage", "5207.129883 153.328003 1932.109985", "-148.242096 0.000000 -0.000000");
      //// -- groggs_riker_south.txt (13 objects)
      SpawnObject("Land_groggs_signage", "12574.599609 44.873699 1328.189941", "-0.842821 0.000000 0.000000");
      SpawnObject("Land_argod_signage", "12518.099609 44.597099 1327.449951", "-1.315009 0.000000 0.000000");
      SpawnObject("Land_wtfsmith_signage", "12534.099609 44.646702 1327.709961", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_ladsbroke_signage", "12589.299805 45.059799 1328.390015", "-0.842821 0.000000 0.000000");
      SpawnObject("ANT_wooden_planks_up", "12817.099609 45.813499 1326.280029", "-2.438184 0.000000 0.000000");
      SpawnObject("ANT_wooden_planks_up", "12817.099609 45.804699 1326.310059", "-3.001848 0.000000 0.000000");
      SpawnObject("Land_notto_signage", "12817.099609 47.570999 1326.160034", "-2.627210 0.000000 0.000000");
      SpawnObject("Land_notto_signage", "12813.700195 49.106201 1326.439941", "87.240410 0.000000 -0.000000");
      SpawnObject("Land_notto_signage", "12812.599609 49.038601 1349.290039", "86.771706 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "12708.200195 49.242401 1390.770020", "-14.073360 0.000000 0.000000");
      SpawnObject("Land_hti_signage", "12716.400391 48.905399 1392.790039", "-13.885963 0.000000 0.000000");
      SpawnObject("Land_torycarvery_signage", "12658.400391 44.744999 1330.010010", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_pissitsmonday_signage", "12711.400391 44.920300 1330.660034", "-0.751889 0.000000 0.000000");
      //// -- groggs_nasper.txt (1 objects)
      SpawnObject("Land_groggs_signage", "9237.389648 153.615997 2508.729980", "179.761642 0.000000 -0.000000");
      //// -- groggs_latina_south.txt (22 objects)
      SpawnObject("Land_groggs_signage", "17727.000000 153.641998 4021.510010", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_ladsbroke_signage", "17649.699219 153.843994 4021.580078", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_hti_signage", "17752.400391 153.401001 4021.429932", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_poots_signage", "17768.300781 153.695007 4021.560059", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "17331.599609 153.679993 4021.350098", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_poondland_signage", "17352.699219 153.667999 4021.409912", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_wtfsmith_signage", "17378.099609 153.417007 4021.330078", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_groggs_signage2", "17666.199219 153.462006 4200.120117", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_specsavedya_signage", "17741.400391 153.613998 4021.449951", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_specsavedya_signage", "17383.599609 152.306000 4021.449951", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_argod_signage", "17758.099609 153.389008 3916.340088", "-179.667755 0.000000 -0.000000");
      SpawnObject("Land_torycarvery_signage", "17770.699219 153.285004 3916.270020", "179.954529 0.000000 -0.000000");
      SpawnObject("Land_chickenslut_signage", "17666.199219 153.464005 4179.220215", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_pissitsmonday_signage", "17666.300781 153.417999 4140.540039", "-90.895279 0.000000 -0.000000");
      SpawnObject("Land_notto_signage", "17677.900391 153.662994 4031.649902", "-179.951035 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "17699.099609 153.658005 4031.550049", "-179.951035 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_up", "17757.900391 154.255997 4344.930176", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "17757.900391 155.957993 4344.979980", "-179.674774 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "17761.400391 157.483002 4344.569824", "-90.000000 0.000000 0.000000");
      SpawnObject("Land_tosco_signage", "17760.000000 157.445999 4320.660156", "0.094421 0.000000 -0.000000");
      SpawnObject("Land_groggs_signage2", "17568.000000 153.460999 4218.490234", "-0.469119 0.000000 -0.000000");
      SpawnObject("Land_chickenslut_signage", "17539.000000 153.455994 4218.379883", "-0.750579 0.000000 -0.000000");
      //// -- groggs_flipton.txt (1 objects)
      SpawnObject("Land_groggs_signage", "7528.430176 159.595993 4006.360107", "162.503448 0.000000 -0.000000");
      //// -- Groggs.txt (20 objects)
      SpawnObject("Land_groggs_signage", "17460.300781 153.412994 3587.709961", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_groggs_signage", "17462.199219 152.876007 3591.070068", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_groggs_signage", "17461.800781 152.860992 3591.120117", "90.000000 0.000000 -0.000000");
      SpawnObject("Land_Cupboard_Door_1", "17462.099609 152.908005 3592.300049", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_Cupboard_Door_1", "17462.099609 152.908997 3592.560059", "-89.366951 0.000000 0.000000");
      SpawnObject("Land_Cupboard_Door_1", "17462.099609 152.839996 3590.010010", "-88.903564 0.000000 0.000000");
      SpawnObject("Land_Cupboard_Door_1", "17462.099609 152.834000 3589.590088", "-90.895279 0.000000 -0.000000");
      SpawnObject("Land_Cupboard_Door_1", "17462.099609 152.863007 3591.110107", "-89.366951 0.000000 0.000000");
      SpawnObject("Land_Cupboard_Door_1", "17462.000000 152.914993 3592.659912", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_Cupboard_Door_1", "17462.000000 152.921997 3591.790039", "-91.415512 0.000000 -0.000000");
      SpawnObject("Land_Cupboard_Door_1", "17462.000000 152.893005 3589.520020", "-91.415512 0.000000 -0.000000");
      SpawnObject("Land_Cupboard_Door_1", "17462.000000 152.895004 3590.040039", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_Cupboard_Door_1", "17462.000000 152.873993 3591.080078", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_Cupboard_Door_1", "17462.000000 152.876999 3590.459961", "-90.633041 0.000000 -0.000000");
      SpawnObject("Land_groggs_signage2", "17461.699219 154.475998 3602.719971", "179.674774 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_up", "17474.500000 152.253006 3595.070068", "-89.366951 0.000000 0.000000");
      SpawnObject("ANT_wooden_planks_up", "17474.699219 152.246002 3595.080078", "90.000000 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "17474.900391 155.595993 3598.419922", "-179.765686 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "17497.699219 155.589005 3598.419922", "179.951035 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "17474.500000 154.031998 3595.040039", "89.884087 0.000000 -0.000000");
      //// -- Grggs_Locksley.txt (9 objects)
      SpawnObject("Land_groggs_signage", "16184.200195 170.279999 5183.310059", "152.745300 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_up", "16236.799805 169.125000 5173.330078", "91.550667 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_up", "16236.900391 169.108994 5173.350098", "90.000000 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "16236.900391 170.860992 5173.399902", "-90.000000 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "16236.400391 172.412003 5169.939941", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "16213.599609 172.429993 5170.029785", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_up", "16091.099609 168.929993 5185.479980", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_poots_signage", "16091.200195 170.854004 5185.470215", "-179.206131 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "16212.599609 172.369995 5184.000000", "89.977844 0.000000 -0.000000");
      //// -- greased_latina.txt (5 objects)
      SpawnObject("ANT_wooden_planks_down", "17599.699219 154.669998 4426.069824", "90.000000 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_down", "17599.599609 154.660004 4429.080078", "-90.000000 0.000000 -0.000000");
      SpawnObject("ANT_wooden_planks_down", "17599.699219 154.654007 4424.870117", "-88.325081 0.000000 0.000000");
      SpawnObject("Land_greasedandreleased_signage", "17599.099609 155.591995 4421.759766", "-91.096420 0.000000 -0.000000");
      SpawnObject("Land_greasedandreleased_signage", "17599.400391 155.395996 4432.479980", "-88.584480 0.000000 0.000000");
      //// -- crookes.txt (1 objects)
      SpawnObject("Land_argod_signage", "17675.500000 153.718002 4194.350098", "89.883682 0.000000 -0.000000");
      //// -- argod_latina.txt (1 objects)
      SpawnObject("Land_argod_signage", "17675.500000 153.718002 4194.350098", "89.883682 0.000000 -0.000000");
      //// -- Angelofthenorth.txt (1 objects)
      SpawnObject("Land_AngelOTN", "6151.209961 211.860001 6304.970215", "-61.831993 0.000000 -0.000000");
      //// -- ZOOTOPIA.txt (1 objects)
      SpawnObject("Land_groggs_signage2", "9869.580078 164.089996 4285.640137", "0.000000 0.000000 -0.000000");
      //// -- WELL FARM MON.txt (1 objects)
      SpawnObject("Land_Misc_Well_Pump_Blue", "13661.299805 149.358002 6887.000000", "115.029015 0.000000 -0.000000");
      //// -- WAF Bunker climb over.txt (9 objects)
      SpawnObject("ANT_roadblock_woodencrate", "2652.739990 246.166000 6823.020020", "-88.449318 0.000000 0.000000");
      SpawnObject("ANT_roadblock_woodencrate", "2652.750000 246.811996 6823.049805", "-89.366951 0.000000 0.000000");
      SpawnObject("ANT_roadblock_woodencrate", "2653.850098 246.192001 6823.270020", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_misc_woodencrate_5x", "2651.830078 246.863998 6821.680176", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_misc_woodencrate_3x", "2653.580078 246.639008 6821.479980", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_misc_woodencrate", "2652.850098 246.218002 6820.339844", "-91.096420 0.000000 -0.000000");
      SpawnObject("ANT_misc_woodencrate", "2652.770020 247.440002 6823.089844", "-87.098770 0.000000 0.000000");
      SpawnObject("ANT_misc_woodencrate", "2653.870117 246.826004 6823.299805", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_misc_woodencrate", "2655.189941 246.201996 6823.310059", "-79.751152 0.000000 -0.000000");
      //// -- vladton well.txt (1 objects)
      SpawnObject("Land_Misc_Well_Pump_Yellow", "17652.400391 31.784901 8452.940430", "0.000000 0.000000 -0.000000");
      //// -- tosco_latina.txt (9 objects)
      SpawnObject("ANT_wooden_planks_up", "17113.400391 152.257004 4517.729980", "-89.366951 0.000000 0.000000");
      SpawnObject("ANT_wooden_planks_up", "17113.500000 152.279007 4517.720215", "-89.366951 0.000000 0.000000");
      SpawnObject("Land_tosco_signage", "17113.400391 154.011002 4517.709961", "90.000000 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "17113.800781 155.606995 4521.129883", "179.954529 0.000000 -0.000000");
      SpawnObject("Land_tosco_signage", "17136.699219 155.548004 4520.939941", "-179.769196 0.000000 -0.000000");
      SpawnObject("Land_groggs_signage2", "17144.900391 153.455002 4527.279785", "179.667755 0.000000 -0.000000");
      SpawnObject("Land_greasedandreleased_signage", "17116.199219 156.358002 4558.830078", "89.366951 0.000000 -0.000000");
      SpawnObject("Land_greasedandreleased_signage", "17116.099609 156.410995 4582.450195", "89.366951 0.000000 -0.000000");
      SpawnObject("Land_greasedandreleased_signage", "17117.400391 156.294998 4557.709961", "0.000000 0.000000 -0.000000");
      //// -- south_island_overpass.txt (1 objects)
      SpawnObject("StaticObj_Bridge_Wood_50_1", "4092.320068 3.635680 1396.410034", "-28.991842 0.000000 -0.000000");
      //// -- sneakbridge.txt (8 objects)
      SpawnObject("StaticObj_Bridge_Wood_50", "13911.099609 148.770004 7005.569824", "1.969231 0.000000 -0.000000");
      SpawnObject("StaticObj_Bridge_Wood_50", "13875.099609 148.479996 7006.729980", "1.594864 0.000000 -0.000000");
      SpawnObject("StaticObj_Bridge_Wood_50", "13841.299805 148.505005 7007.049805", "-0.657461 0.000000 0.000000");
      SpawnObject("StaticObj_Bridge_Wood_50_1", "10964.900391 143.901993 6768.169922", "75.908859 0.000000 -0.000000");
      SpawnObject("StaticObj_Bridge_Wood_50", "10973.599609 145.231995 6733.830078", "75.624390 0.000000 -0.000000");
      SpawnObject("StaticObj_Bridge_Wood_50", "10982.299805 145.199997 6699.450195", "75.908859 0.000000 -0.000000");
      SpawnObject("StaticObj_Bridge_Wood_25", "10986.500000 145.212006 6682.430176", "76.096817 0.000000 -0.000000");
      SpawnObject("StaticObj_Bridge_Wood_25", "13938.200195 148.955002 7004.439941", "1.125899 0.000000 -0.000000");
      //// -- shatwest_tower.txt (6 objects)
      SpawnObject("StaticObj_Furniture_SofaCorner", "17557.500000 181.584000 4166.580078", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Furniture_sofa_leather_new", "17558.199219 181.554993 4169.020020", "-91.479050 0.000000 -0.000000");
      SpawnObject("Chalkboard_1", "17554.199219 181.750000 4166.259766", "-86.412239 0.000000 -0.000000");
      SpawnObject("StaticObj_Furniture_lobby_chair", "17543.099609 181.166000 4168.569824", "-66.333984 0.000000 -0.000000");
      SpawnObject("StaticObj_Furniture_lobby_chair", "17543.099609 181.158997 4166.839844", "-100.298737 0.000000 -0.000000");
      SpawnObject("ANT_church_chair", "17548.500000 181.787003 4162.259766", "-179.862442 0.000000 -0.000000");
      //// -- Angelofthenorth.txt (1 objects)
      SpawnObject("Land_AngelOTN", "6151.209961 211.860001 6304.970215", "-61.831993 0.000000 -0.000000");
      //// -- westminster.txt (28 objects)
      SpawnObject("Land_westminster", "16917.000000 155.492996 4921.000000", "-1.000361 1.000209 0.040328");
      SpawnObject("Land_Westminsterdoor", "16908.699219 150.041000 4886.660156", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_Westminsterdoor", "16904.800781 150.076004 4890.370117", "89.366951 0.000000 -0.000000");
      SpawnObject("Land_rubbish_floor_1", "16904.199219 150.160995 4888.229980", "0.000000 0.000000 -0.000000");
      SpawnObject("Land_rubbish_floor_1", "16903.500000 150.130997 4888.919922", "-2.627210 0.000000 0.000000");
      SpawnObject("StaticObj_Garbage_Pile1", "16902.099609 150.548004 4888.419922", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Garbage_Pile2", "16902.599609 150.186996 4891.810059", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Garbage_Pile3", "16899.699219 150.210007 4889.740234", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Garbage_Pile4", "16903.000000 150.334000 4902.470215", "74.775604 0.000000 -0.000000");
      SpawnObject("StaticObj_Garbage_Pile5", "16913.000000 150.395004 4884.140137", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Garbage_Pile6", "16905.599609 150.315002 4884.660156", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_DirtPile_Medium2", "16903.300781 150.313995 4893.680176", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Glass", "16901.300781 150.143997 4897.689941", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Glass", "16903.599609 150.078003 4886.770020", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Glass", "16900.599609 150.091995 4892.700195", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Glass", "16903.000000 150.091995 4900.830078", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Wood1", "16900.900391 150.283005 4903.379883", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_DirtPile_Medium2", "16917.400391 150.470993 4883.910156", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_DirtPile_Medium1", "16918.400391 150.654999 4886.129883", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_DirtPile_Large", "16920.300781 150.912994 4886.640137", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_DirtPile_Large", "16896.300781 150.695007 4907.439941", "79.000366 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Concrete1", "16897.699219 152.464005 4936.569824", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Concrete2", "16910.599609 150.651001 4939.189941", "0.000000 0.000000 -0.000000");
      SpawnObject("StaticObj_Rubble_Bricks2", "16911.099609 152.216003 4946.479980", "-74.123383 0.000000 0.000000");
      SpawnObject("StaticObj_Rubble_DirtPile_Large", "16920.099609 151.927994 4954.890137", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_decal_heli_army", "16891.699219 152.091995 4970.939941", "0.000000 0.000000 -0.000000");
      SpawnObject("ANT_garbage_pile5", "16911.800781 151.703003 4953.649902", "0.000000 0.000000 -0.000000");
      SpawnObject("car3", "16911.000000 151.884003 4957.450195", "-14.918700 4.000000 -0.000000");
      //// -- tardis.txt (1 objects)
      SpawnObject("Land_tardis", "17544.099609 151.856995 4036.370117", "-90.165756 0.000000 -0.000000");
      //// -- stonehenge.txt (2 objects)
      SpawnObject("Land_stonehenge", "15442.200195 207.182007 6974.970215", "50.001686 2.998346 -0.037195");
      SpawnObject("Land_stonehengesign", "15455.500000 207.350998 6988.089844", "-79.561623 0.000000 -0.000000");
      //// -- Mansion.txt (30 objects)
      SpawnObject( "OU_dk", "4353.279785 213.961996 4582.430176", "-83.119339 0.000000 0.000000" );
      SpawnObject( "StaticObj_Misc_Fountain", "4355.339844 208.707993 4595.879883", "7.505145 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Statue_Enoch1", "4369.629883 209.531006 4590.629883", "109.773041 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Statue_Enoch1", "4341.319824 209.511002 4595.180176", "-82.189369 0.000000 0.000000" );
      SpawnObject( "Land_Misc_Greenhouse", "4317.640137 209.457993 4585.500000", "-174.508194 0.000000 -0.000000" );
      SpawnObject( "Land_Misc_Greenhouse", "4317.200195 209.464005 4581.430176", "-173.576431 0.000000 -0.000000" );
      SpawnObject( "Land_Shed_W6", "4318.830078 209.513000 4599.549805", "-168.133759 0.000000 -0.000000" );
      SpawnObject( "PSD_cobblestone", "4353.709961 207.893005 4582.770020", "8.999920 0.000000 -0.000000" );
      SpawnObject( "ANT_dam_stone_40", "4350.729980 206.270996 4564.240234", "-169.420914 -89.104088 -1.194936" );
      SpawnObject( "StaticObj_Rubble_DirtPile_Large", "4329.740234 207.733002 4570.620117", "0.000000 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Rubble_DirtPile_Large", "4329.919922 207.380997 4567.310059", "0.000000 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Rubble_DirtPile_Large", "4329.399902 207.589996 4565.580078", "0.000000 8.999920 -2.998346" );
      SpawnObject( "StaticObj_Rubble_DirtPile_Large", "4329.569824 207.722000 4569.169922", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_garbage_pile7", "4325.770020 207.664001 4570.819824", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_garbage_pile7", "4324.970215 207.432999 4569.109863", "-161.473129 0.000000 -0.000000" );
      SpawnObject( "ANT_garbage_pile8", "4325.379883 207.919006 4569.930176", "0.000000 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4338.669922 209.042007 4606.359863", "99.078606 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4336.060059 209.029007 4604.500000", "9.288628 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4335.560059 209.056000 4601.450195", "9.288580 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4343.259766 209.029007 4605.629883", "-81.064529 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4347.729980 209.029007 4604.919922", "-80.970901 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4375.229980 209.029007 4600.609863", "-81.533394 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4370.830078 209.029007 4601.279785", "-81.346138 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4366.350098 209.029007 4601.970215", "-80.876488 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4362.290039 209.029007 4602.620117", "-80.970833 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4351.830078 209.029007 4604.259766", "-81.345879 0.000000 -0.000000" );
      SpawnObject( "Land_Wall_Gate_Fen3", "4357.069824 209.177994 4603.390137", "8.913297 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4377.200195 209.029007 4598.060059", "8.256555 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4376.569824 209.029007 4593.600098", "7.787429 0.000000 -0.000000" );
      SpawnObject( "hmansion", "4375.950195 209.029007 4589.040039", "8.068853 0.000000 -0.000000" );
      SpawnObject( "ANT_t_salixalba_2s", "4306.220215 213.690002 4600.169922", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_t_salixalba_2s", "4388.149902 213.835999 4598.299805", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_t_salixalba_2s", "4379.709961 212.134995 4544.830078", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_t_salixalba_2sb_swamp", "4359.709961 211.147003 4547.270020", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_t_salixalba_2sb_summer", "4344.180176 207.858994 4552.129883", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_t_salixalba_2s", "4320.459961 210.136002 4557.279785", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_b_prunusspinosa_2s_summer", "4328.649902 210.487000 4598.959961", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_b_prunusspinosa_1s_summer", "4330.850098 209.598999 4596.299805", "0.000000 0.000000 -0.000000" );
      //// ## Devils Arse Optional charger for second endgame (in bunker config below) and milli bits
      SpawnObject( "StaticObj_Power_TransformerStation_Big", "5388.069824 600.882996 9250.910156", "-20.453802 0.000000 -0.000000" );
      SpawnObject( "Land_Mil_Tent_Big2_5", "5366.560059 600.163025 9240.940430", "69.050980 0.000000 -0.000000" );
      SpawnObject( "Land_Mil_Tent_Big2_1", "5377.959961 600.158020 9233.309570", "-20.265724 0.000000 0.000000" );
      SpawnObject( "Land_Medical_Tent_Big", "5404.089844 598.166016 9224.580078", "-22.423368 0.000000 0.000000" );
      SpawnObject( "Land_Medical_Tent_Big", "5401.029785 598.130981 9232.259766", "-22.142517 0.000000 0.000000" );
      SpawnObject( "Land_Mil_Tent_Big1_1", "5386.770020 598.125000 9219.990234", "-164.381775 0.000000 -0.000000" );
      SpawnObject( "Land_Mil_Tent_Big2_3", "5345.959961 600.168030 9224.570313", "-34.904099 0.000000 0.000000" );
      SpawnObject( "Land_Mil_Tent_Big3", "5381.970215 599.192993 9186.000000", "-21.768023 0.000000 0.000000" );
      SpawnObject( "Land_Mil_Tent_Big2_5", "5365.270020 600.161011 9178.639648", "-21.485882 0.000000 0.000000" );
      SpawnObject( "Land_Container_1Mo", "5354.279785 599.270996 9183.910156", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Container_1Mo", "5348.990234 599.273987 9181.389648", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Container_1Mo", "5360.270020 599.323975 9187.809570", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Container_1Mo", "5360.040039 599.252991 9166.639648", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Container_1Mo", "5352.189941 599.255005 9167.690430", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Mil_Tent_Big4", "5373.919922 599.343994 9276.940430", "-62.486481 0.000000 0.000000" );
      SpawnObject( "StaticObj_Mil_CamoNet_Tent2", "5362.450195 600.083984 9266.830078", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_MobileLaboratory", "5359.330078 598.908020 9254.679688", "-91.415512 0.000000 -0.000000" );
      SpawnObject( "Land_MobileLaboratory", "5323.040039 598.854004 9222.559570", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Mil_Tent_Big1_5", "5358.950195 598.101990 9297.940430", "-21.298092 0.000000 0.000000" );
      SpawnObject( "Land_Mil_Tent_Big1_5", "5350.339844 598.181030 9294.389648", "-20.829659 0.000000 0.000000" );
      SpawnObject( "Land_Mil_Tent_Big1_3", "5342.270020 598.132019 9290.809570", "-22.985794 0.000000 0.000000" );
      SpawnObject( "StaticObj_Mil_CamoNet_Side_east", "5332.629883 600.872009 9286.679688", "-24.111162 0.000000 0.000000" );
      SpawnObject( "Land_Roadblock_WoodenCrate", "5335.060059 598.426025 9286.929688", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Roadblock_WoodenCrate", "5329.830078 598.432007 9285.459961", "0.000000 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Misc_WoodenCrate_5x", "5333.069824 599.085022 9288.950195", "0.000000 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Misc_WoodenCrate_5x", "5336.029785 599.085022 9289.519531", "91.415512 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Misc_WoodenCrate_5x", "5360.950195 599.054016 9271.179688", "59.294384 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Misc_WoodenCrate_5x", "5360.350098 599.057007 9265.830078", "0.000000 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Misc_WoodenCrate_3x", "5358.859863 598.789001 9269.209961", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Roadblock_WoodenCrate", "5361.729980 598.390991 9268.169922", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Roadblock_WoodenCrate", "5358.770020 598.426025 9271.480469", "63.897739 0.000000 -0.000000" );
      SpawnObject( "Land_Roadblock_WoodenCrate", "5361.359863 598.393982 9242.299805", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Roadblock_WoodenCrate", "5363.259766 598.395996 9236.660156", "-47.850300 0.000000 0.000000" );
      SpawnObject( "StaticObj_Misc_WoodenCrate_5x", "5394.890137 598.994995 9217.950195", "0.000000 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Misc_WoodenCrate_5x", "5389.089844 599.036987 9239.940430", "0.000000 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Misc_WoodenCrate_5x", "5392.100098 599.080994 9241.330078", "89.104713 0.000000 -0.000000" );
      SpawnObject( "Land_Castle_Donjon", "5353.040039 657.065979 9223.969727", "-22.894657 0.000000 0.000000" );
      SpawnObject( "Land_Castle_Donjon", "5365.830078 656.364014 9229.089844", "-22.141302 0.000000 0.000000" );
      SpawnObject( "Land_Castle_Donjon", "5360.350098 653.406006 9209.290039", "-22.894657 0.000000 0.000000" );
      SpawnObject( "Land_Castle_Donjon", "5351.790039 654.070007 9212.910156", "-18.014950 0.000000 0.000000" );
      SpawnObject( "Land_Castle_Donjon", "5366.290039 656.794983 9217.000000", "-20.736145 0.000000 0.000000" );
      SpawnObject( "ANT_castle_stairs", "5341.669922 646.357971 9199.440430", "69.149002 0.000000 -0.000000" );
      SpawnObject( "Land_Castle_Donjon", "5300.459961 656.687988 9238.889648", "-22.048752 0.000000 -0.000000" );
      SpawnObject( "Land_Castle_Donjon", "5342.660156 657.052979 9253.179688", "-22.236439 0.000000 -0.000000" );
      SpawnObject( "Land_Castle_Donjon", "5328.000000 655.223999 9189.259766", "-22.048824 0.000000 -0.000000" );
      SpawnObject( "ANT_castle_stairs", "5354.759766 635.460999 9290.490234", "-116.054787 0.000000 -0.000000" );
      SpawnObject( "Land_Mil_Tent_Big2_2", "5318.810059 600.065002 9252.620117", "-89.132950 0.000000 -0.000000" );
      //// ## Sector 12
      SpawnObject( "Land_Cave_rock1", "16313.200195 6.567890 16976.199219", "94.762924 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16314.200195 6.197460 16971.800781", "40.062546 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16324.200195 6.119180 16967.199219", "94.762924 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16326.200195 5.552820 16959.900391", "94.762924 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16308.700195 6.628230 16971.800781", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16304.099609 6.511570 16971.400391", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16300.900391 6.503830 16969.699219", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16296.799805 6.252860 16967.900391", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16292.099609 5.613590 16966.900391", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16287.000000 6.086680 16968.199219", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16279.599609 6.319130 16967.099609", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16274.799805 6.764260 16965.900391", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16273.700195 6.890220 16965.300781", "-58.921944 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16264.799805 8.867050 16956.500000", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16261.400391 6.386400 16961.800781", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16264.799805 7.095250 16964.099609", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16262.200195 3.972660 16957.599609", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16326.900391 1.154940 16959.400391", "94.762924 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16261.700195 0.564513 16955.099609", "121.409027 0.000000 -0.000000" );
      SpawnObject( "Land_Cave_rock1", "16264.500000 4.039150 16954.599609", "23.456175 0.000000 -0.000000" );
      
      //// ## Ship
      SpawnObject( "Land_Ship_Big_FrontA", "9452.860352 17.975201 10516.500000", "-0.279766 0.000000 0.000000" );
      SpawnObject( "Land_Ship_Big_FrontB", "9433.049805 16.416300 10514.200195", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Ship_Big_BackA", "9394.040039 11.637800 10524.400391", "23.000095 0.000000 0.000000" );
      SpawnObject( "Land_Ship_Big_BackB", "9376.240234 10.160900 10532.599609", "23.268837 0.000000 -0.000000" );
      SpawnObject( "Land_Ship_Big_Castle", "9386.570313 20.419300 10528.099609", "22.893044 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Misc_Flagpole", "9413.709961 1.829240 10515.500000", "0.000000 0.000000 -68.000000" );
      SpawnObject( "Land_Container_1Mo", "9429.889648 2.075300 10506.799805", "90.353340 0.000000 -0.000000" );
      SpawnObject( "Land_Container_1Mo", "9354.290039 3.438110 10541.500000", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Container_1Mo", "9362.830078 3.424700 10542.599609", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Container_1Mo", "9464.599609 8.667980 10515.000000", "-36.591522 0.000000 -0.000000" );
      SpawnObject( "Land_Container_1Mo", "9444.139648 1.956480 10515.000000", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Container_1Mo", "9449.419922 1.974190 10513.500000", "0.000000 0.000000 -0.000000" );      
      //// ## Minor fixes
      SpawnObject( "StaticObj_Misc_WoodenCrate", "16431.500000 151.261002 3359.139893", "0.000000 0.000000 -0.000000" );
      SpawnObject( "StaticObj_Misc_WoodenCrate", "16431.500000 151.656998 3359.139893", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Misc_FireBarrel_Green", "7437.379883 151.714005 7250.890137", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_rock_monolith1", "9564.849609 48.777401 15813.000000", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_rock_monolith1", "9568.980469 42.457298 15792.500000", "-32.557579 0.000000 0.000000" );
      SpawnObject( "ANT_rock_monolith1", "9571.410156 44.448601 15809.599609", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_rock_monolith1", "9554.049805 33.676601 15751.500000", "34.432133 0.000000 -0.000000" );
      SpawnObject( "ANT_rock_monolith1", "9573.120117 33.058102 15759.400391", "95.873093 0.000000 -0.000000" );
      SpawnObject( "ANT_rock_monolith1", "9586.500000 36.082802 15750.000000", "0.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_rock_monolith1", "9585.389648 34.752800 15729.000000", "48.132469 0.000000 -0.000000" );
      SpawnObject( "ANT_rock_monolith1", "9572.700195 35.260700 15723.500000", "71.397392 0.000000 -0.000000" );
      SpawnObject( "ANT_rock_monolith1", "9555.870117 33.834999 15730.500000", "-37.906872 0.000000 0.000000" );
      SpawnObject( "ANT_misc_woodencrate_3x", "11370.200195 165.207001 5753.060059", "-112.969109 0.000000 -0.000000" );
      SpawnObject( "ANT_misc_woodencrate", "11370.400391 163.731003 5752.750000", "66.613281 0.000000 -0.000000" );
      SpawnObject( "ANT_misc_woodencrate", "11370.500000 164.164001 5752.750000", "67.740250 0.000000 -0.000000" );
      SpawnObject( "ANT_castle_stairs_nolc", "9592.030273 9.358870 15752.900391", "130.979477 0.000000 -0.000000" );
      SpawnObject( "ANT_bridge_wood_25", "3947.860107 4.891000 1314.660034", "-29.836273 0.000000 -0.000000" );
      //NAF PATCH--------------------------------------
      SpawnObject( "land_bunkerpuzzle_wandgross", "9250.259766 127.037003 9525.759766", "-49.783558 0.000000 0.000000" );
      SpawnObject( "land_bunkerpuzzle_wandgross", "9239.750000 127.143997 9513.570313", "-49.859447 0.000000 0.000000" );
      SpawnObject( "ANT_slum_roof5", "9254.049805 132.494995 9513.000000", "42.999802 3.000000 2.984170" );
      //Arctic Temple--------------------------------------
      SpawnObject( "Land_Ant_Endgame_Arctic_Console", "19659.300781 9.168340 18241.300781", "17.077486 0.000000 -0.000000" );
      //Volcano
      SpawnObject( "fmdpk_modscifiwalls_gearstorage", "1637.729980 16.576000 18433.500000", "269.104713 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_medicalcab", "1620.489990 16.586500 18429.400391", "89.366959 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_lockers", "1614.050049 20.738701 18468.199219", "240.245979 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_lockers", "1613.150024 20.738701 18469.800781", "240.245979 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_gearstorage", "1612.239990 20.738701 18464.400391", "331.852631 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_gearstorage", "1614.189941 20.738701 18470.800781", "151.582615 0.000000 0.000000");
      SpawnObject( "fmdpk_modscifiwalls_static_storageshelf", "1615.689941 20.738701 18471.800781", "-29.235687 0.000000 0.000000");
      SpawnObject( "fmdpk_modscifiwalls_static_storageshelf", "1616.910034 20.738701 18472.500000", "-29.235687 0.000000 0.000000");
      SpawnObject( "fmdpk_modscifiwalls_static_cafetable", "1620.569946 20.738701 18465.900391", "0.000000 0.000000 -0.000000");
      SpawnObject( "Land_AntoriaBunkerKeyCardTwinDoor", "1605.040039 16.910500 18466.400391", "-28.417385 0.000000 0.000000");
      SpawnObject( "fmdpk_modscifiwalls_container", "1582.079956 20.738701 18480.199219", "151.511002 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_medicalcab", "1577.790039 20.738701 18486.099609", "61.139023 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_gearstorage", "1593.729980 20.738701 18490.300781", "61.001659 0.000000 -0.000000");
      SpawnObject( "Land_AntoriaBunkerKeyCardDoor", "1602.920044 20.738701 18464.000000", "62.028217 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_container", "1596.660034 20.738701 18460.400391", "0.000000 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_container", "1594.069946 20.738701 18458.800781", "-60.112377 0.000000 0.000000");
      SpawnObject( "fmdpk_modscifiwalls_container", "1597.790039 20.738701 18452.000000", "180.000000 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_static_greeble_1", "1601.560059 20.738701 18458.400391", "151.646194 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_static_greeble_2", "1603.430054 20.738701 18459.800781", "149.461456 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_static_medicalcab", "1597.869995 20.738701 18461.400391", "-118.788445 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_lockers", "1581.719971 20.738701 18489.699219", "-119.549011 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_container", "1596.390015 20.738701 18498.199219", "0.000000 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_gearstorage", "1598.550049 20.738701 18498.000000", "60.864899 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_container", "1605.130005 20.738701 18494.099609", "88.325081 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_lockers", "1602.680054 20.738701 18500.699219", "-119.470917 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_lockers", "1603.599976 20.738701 18499.000000", "-119.746964 0.000000 -0.000000");
      SpawnObject( "Land_AntoriaBunkerKeyCardDoor", "1592.579956 20.738701 18496.000000", "62.028217 0.000000 -0.000000");
      SpawnObject( "Land_AntoriaBunkerKeyCardDoor", "1587.050049 20.738701 18493.000000", "61.953747 0.000000 -0.000000");
      SpawnObject( "Land_AntoriaBunkerKeyCardTwinDoor", "1583.739990 16.910500 18505.300781", "-29.099524 0.000000 0.000000");
      SpawnObject( "Land_AntoriaBunkerKeyCardDoor", "1589.479980 20.738701 18476.099609", "-118.518600 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_container", "1584.020020 20.738701 18477.500000", "-83.478981 0.000000 0.000000");
      SpawnObject( "Land_AntoriaBunkerKeyCardDoor", "1601.650024 20.738701 18478.900391", "61.408234 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_medicalcab", "1611.599976 20.738701 18483.599609", "-29.303839 0.000000 0.000000");
      SpawnObject( "fmdpk_modscifiwalls_labdesk", "1607.150024 20.738701 18487.500000", "151.303894 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_officechair", "1607.890015 20.738701 18486.500000", "132.797058 0.000000 -0.000000");
      SpawnObject( "Land_AntoriaBunkerKeyCardDoor", "1580.459961 20.738701 18505.000000", "61.820160 0.000000 -0.000000");
      SpawnObject( "Land_AntoriaBunkerKeyCardDoor", "1585.760010 20.738701 18507.900391", "61.204292 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_lockers", "1592.219971 20.738701 18510.699219", "-27.938635 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_lockers", "1593.829956 20.738701 18511.599609", "-27.870373 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_lockers", "1595.430054 20.738701 18512.400391", "-28.280306 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_gearstorage", "1590.800049 20.738701 18520.900391", "153.285507 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_gearstorage", "1589.150024 20.738701 18519.900391", "152.466049 0.000000 -0.000000");
      SpawnObject( "Land_AntoriaBunkerKeyCardDoor", "1594.939941 16.957800 18481.699219", "-27.118996 0.000000 -0.000000" );
      SpawnObject( "Land_AntoriaBunkerKeyCardDoor", "1579.160034 16.948299 18510.500000", "-28.416883 0.000000 -0.000000" );
      SpawnObject( "Land_AntoriaBunkerKeyCardDoor", "1608.239990 20.738701 18466.900391", "61.342041 0.000000 -0.000000");
      SpawnObject( "fmdpk_modscifiwalls_lockers", "1574.449951 20.738701 18501.199219", "-27.323912 0.000000 -0.000000" );
      SpawnObject( "fmdpk_modscifiwalls_lockers", "1572.849976 20.738701 18500.300781", "-28.963392 0.000000 -0.000000" );
      SpawnObject( "fmdpk_modscifiwalls_container", "1569.930054 20.738701 18504.599609", "-104.036018 0.000000 -0.000000" );
      SpawnObject( "fmdpk_modscifiwalls_container", "1569.750000 20.738701 18507.500000", "0.000000 0.000000 -0.000000" );
      SpawnObject( "fmdpk_modscifiwalls_doorframe_laser", "1843.920044 16.545000 18059.900391", "70.082733 0.000000 -0.000000" );
      SpawnObject( "Land_FlatRock_1", "19717.300781 14.917700 18341.699219", "0.000000 0.000000 -78.001472" );
      SpawnObject( "fmdpk_modscifiwalls_doorframe_laser_wide", "19717.000000 8.250630 18342.000000", "90.000000 0.000000 -0.000000" );
      SpawnObject( "ANT_power_vhv_end", "19652.800781 15.024000 18236.900391", "34.086639 0.000000 -0.000000" );
      //waterfall
      SpawnObject( "ANT_rock_bright_wallh1", "6555.790039 133.563995 1967.619995", "-38.048840 0.000000 0.000000" );
      SpawnObject( "ANT_rock_bright_wallh1", "6550.629883 137.332001 1964.699951", "71.998749 0.000000 -0.000000" );
      SpawnObject( "ANT_rock_bright_wallh1", "6551.120117 134.895996 1972.099976", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Waterfall_EdgeFillLongDrop", "6535.109863 128.759003 1955.449951", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Waterfall_WideStrip6m", "6529.129883 131.320007 1963.339966", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Waterfall_WideStrip6m", "6538.919922 131.205994 1962.339966", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Waterfall_WideStrip6m", "6536.080078 139.354996 1955.459961", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Waterfall_WideStrip6m", "6546.209961 123.280998 1945.900024", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Waterfall_WideStrip6m", "6526.009766 138.447998 1961.349976", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Waterfall_EdgeFillLongDrop", "6537.540039 128.951004 1949.420044", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Waterfalltest_Drop5", "6548.680176 121.671997 1948.170044", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Waterfalltest_Drop5", "6522.990234 122.805000 1955.199951", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Waterfalltest_Combo5", "6542.580078 123.094002 1950.900024", "0.000000 0.000000 -0.000000" );
      SpawnObject( "Land_Waterfalltest_Combo5", "6530.029785 123.094002 1955.010010", "0.000000 0.000000 -0.000000" );

      
        //INIT ECONOMY--------------------------------------
        Hive ce = CreateHive();
        if (ce)
                ce.InitOffline();

        //DATE RESET AFTER ECONOMY INIT-------------------------
        int year, month, day, hour, minute;
        int reset_month = 2, reset_day = 20;

        GetGame().GetWorld().GetDate(year, month, day, hour, minute);

        if ((month == reset_month) && (day < reset_day)) {
                GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
        } else {
                if ((month == reset_month + 1) && (day > reset_day)) {
                        GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
                } else {
                        if ((month < reset_month) || (month > reset_month + 1)) {
                                GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
                        }
                }
        }
        //corrected export data for mapsize, ElektroVodka
        // CEApi TestHive = GetCEApi();
        // TestHive.ExportProxyProto();
        // TestHive.ExportProxyData( "10240 0 10240", 26384 );
        // TestHive.ExportClusterData();     

        // =============================================== BUNKER GENERATOR ===============================================
        if (GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            vector bunkerOrigin = "19547.75 25.25 782.76";
            CleanupSciFiWalls(bunkerOrigin, 350.0); // CLEAN-UP LAST BUNKER SETUP
            SpawnDIBunkerObject("fmdpk_landingpad_1", "19726.5 71.16 933.31", "-125 0 0", 1); // SPAWN LANDINGPAD
            GenerateMap(bunkerOrigin);
            SpawnDIBunkerObject( "fmdpk_landingpad_cardterminal", "19571.7 80.472200 651.671", "115.0 0 0", 1);
            SpawnDIBunkerObject( "fmdpk_landingpad_cardterminal", "5379.09 598.18 9258.410", "70.74 0 0", 1); 
            SpawnDIBunkerObject( "fmdpk_landingpad_cardterminal", "1587.089966 20.738701 18471.900391", "0.000000 0.000000 -0.000000",1);

            // SpawnCustomBunkerObj();
            // vector gasOrigin = "5512 472 8586"; // SPAWN GAS ZONE
            // SpawnDIBunkerObject("ContaminatedArea_Static", gasOrigin, "0 0 0", 1.0); // SPAWN GAS ZONE
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(FP_StartBunkerZone, 1000, false); // SPAWN ZOMBIE AI
        }
        // =============================================== BUNKER GENERATOR ===============================================		
        
    }

class CustomMission: MissionServer {
        void SetRandomHealth(EntityAI itemEnt) {
                if (itemEnt) {
                        int rndHlt = Math.RandomInt(55, 100);
                        itemEnt.SetHealth("", "", rndHlt);
                }
        }

        override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName) {
                Entity playerEnt;
                string characterType = characterName;

                // IMPORTANT:
                // characterName is what DayZ passes from the respawn/menu choice.
                // - Custom should use the player's saved/customised menu character.
                // - Random should already arrive here as a valid random character.
                // If the passed character is empty/invalid, only then fall back to CreateRandomPlayer().
                if (characterType == "" || GetGame().ListAvailableCharacters().Find(characterType) == -1)
                {
                        characterType = GetGame().CreateRandomPlayer();
                        Print("[FF_SPAWN] CreateCharacter fallback random selectedType=" + characterType + " originalCharacterName=" + characterName);
                }
                else
                {
                        Print("[FF_SPAWN] CreateCharacter selectedType=" + characterType + " originalCharacterName=" + characterName);
                }

                playerEnt = GetGame().CreatePlayer(identity, characterType, pos, 0, "NONE");

                Class.CastTo(m_player, playerEnt);

                GetGame().SelectPlayer(identity, m_player);

                return m_player;
        }

        override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
{
        // Clean slate first
        player.RemoveAllItems();

        EntityAI itemEnt;
        ItemBase itemBs;

        // --- Random Antoria T-shirt: equal chance for every custom shirt ---
        TStringArray freshyShirts = {
                "AntoriaShirt",
                "CostCutter",
                "MarmiteShirt",
                "AntoriaHasFallenShirt",
                "TescoShirt",
                "OffWhiteShirt",
                "NettoShirt",
                "Only_Fools_And_Horses_Shirt",
                "Tag_Youre_It_Shirt",
                "FirstKnifeShirt",
                "LetsSacrificeTobyShirt",
                "LetsSummonDemonsShirt",
                "PyrokinesisShirt",
                "TheLegendTheMythShirt",
                "DoYouKnowWhoIAm",
                "FluffsterShirt",
                "SchoolboyShirt",
                "ArthurDailyShirt",
                "BomberClanShirt",
                "CitizenDannyCTZNShirt",
                "CrumpetRewardShirt",
                "FreshlySpawnedShirt",
                "HeyBarmbysChernarusShirt",
                "MullerLiveShirt",
                "RonnyZShirt",
                "SenmuChickenShirt",
                "SundayShirt"
        };

        string selectedShirt = freshyShirts.GetRandomElement();
        player.GetInventory().CreateInInventory(selectedShirt);

        player.GetInventory().CreateInInventory("JumpsuitPants_Grey");
        player.GetInventory().CreateInInventory("HikingBoots_Black");
        player.GetInventory().CreateInInventory("Apple");
        player.GetInventory().CreateInInventory("Plum");
        player.GetInventory().CreateInInventory("BoneKnife");

        // --- Universal gear ---
        itemEnt = player.GetInventory().CreateInInventory("BandageDressing");
        itemBs = ItemBase.Cast(itemEnt);
        if (itemBs)
        {
                itemBs.SetQuantity(4);
        }

        //Full tequila bottle for every fresh spawn
        itemEnt = player.GetInventory().CreateInInventory("CPM_TequilaBottle");
        itemBs = ItemBase.Cast(itemEnt);
        if (itemBs)
        {
                itemBs.SetQuantity(1000);
                itemBs.SetLiquidType(1073741824);
        }
}
};

Mission CreateCustomMission(string path) {
        return new CustomMission();
}
