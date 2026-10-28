void GenerateMap(vector origin)
{
    array<ref BaseLayout> layouts = new array<ref BaseLayout>;
    // layouts.Insert( new Layout_CustomGrid11x12 );
    //layouts.Insert( new Layout_CustomGrid20x19 );
    //layouts.Insert( new Layout_CustomGrid20x20 );
    //layouts.Insert( new Layout_CustomGrid22x27 );
    //layouts.Insert( new Layout_Plus12Rooms_25x25 );
    // layouts.Insert( new Layout_CustomGridCustom1 );
    // layouts.Insert( new Layout_CustomGrid41x41 );
    // layouts.Insert( new Layout_SmallBunker_1 );
    // layouts.Insert( new Layout_SmallBunker_2 );
    // layouts.Insert( new Layout_MediumBunker_1 );
    //layouts.Insert( new Layout_MediumBunker_2 );
    // layouts.Insert( new Layout_LargeBunker_1 );
    // layouts.Insert( new Layout_LargeBunker_2 );
    layouts.Insert( new Layout_2FloorMazeBunker );
    //layouts.Insert( new Layout_OpenAreaBunker );
    //layouts.Insert( new Layout_11x11_3xFullGearRooms );
    // layouts.Insert( new Layout_ModularTest );

    if (layouts.Count() == 0)
    {
        Error("[BunkerGenerator] No layouts inserted in GenerateMap()");
        return;
    }

    int choice = Math.RandomInt(0, layouts.Count());
    Print("[BunkerGenerator] Spawning Layout ID: " + layouts[choice]);
    layouts[choice].Spawn(origin);
}

void CleanupSciFiWalls(vector center, float radius = 350.0)
{
    array<Object> foundObjects = new array<Object>;
    array<CargoBase> proxyCargos = new array<CargoBase>;

    g_Game.GetObjectsAtPosition(center, radius, foundObjects, proxyCargos);

    for (int i = foundObjects.Count() - 1; i >= 0; i--)
    {
        Object obj = foundObjects[i];
        if (!obj)
            continue;

        string typeName = obj.GetType();
        typeName.ToLower();

        if (typeName.Contains("fmdpk_modscifiwalls_"))
        {
            g_Game.ObjectDelete(obj);
        }
    }
}

// RANDOM BUNKER GENERATOR SPAWNER ===========================================
static Object SpawnDIBunkerObject(string type, vector position, vector orientation, float scale = 1.0)
{
    Object obj;

    if (type.Contains(".p3d"))
    {
        obj = g_Game.CreateStaticObjectUsingP3D(type, position, orientation, scale, false);
    }
    else
    {
        obj = g_Game.CreateObjectEx(type, position, ECE_SETUP | ECE_CREATEPHYSICS | ECE_UPDATEPATHGRAPH | ECE_NOLIFETIME | ECE_NOPERSISTENCY_WORLD);
    }

    if (!obj)
    {
        Error("Failed to create object " + type);
        return null;
    }

    obj.SetPosition(position);
    obj.SetOrientation(orientation);
    obj.SetOrientation(obj.GetOrientation());
    obj.SetScale(scale);
    obj.Update();

    if (obj.CanAffectPathgraph())
    {
        obj.SetAffectPathgraph(true, false);
        g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(g_Game.UpdatePathgraphRegionByObject, 100, false, obj);
    }

    return obj;
}
