#ifndef MYSENSITIVEDETECTOR_HH
#define MYSENSITIVEDETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "globals.hh"
#include <map>

class MySensitiveDetector : public G4VSensitiveDetector {
public:
    MySensitiveDetector(const G4String& name, const G4String& hitsCollectionName);
    virtual ~MySensitiveDetector();

    virtual void Initialize(G4HCofThisEvent*) override;
    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory*) override;
    virtual void EndOfEvent(G4HCofThisEvent*) override;

private:
    G4double fTotalEnergyDep;  // Total energy deposition across all volumes
    std::map<G4String, G4double> fEnergyDepMap;  // Energy deposition for each volume
};

#endif


