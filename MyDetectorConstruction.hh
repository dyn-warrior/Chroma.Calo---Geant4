#ifndef MYDETECTORCONSTRUCTION_HH
#define MYDETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "globals.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction {
public:
    MyDetectorConstruction();
    virtual ~MyDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();

private:
    G4LogicalVolume* logicShape1;
    G4LogicalVolume* logicShape2;
    G4LogicalVolume* logicShape3;
    G4LogicalVolume* logicShape4;
    G4LogicalVolume* logicShape5;
};

#endif
