#ifndef MYRUNACTION_HH
#define MYRUNACTION_HH

#include "G4UserRunAction.hh"
#include "globals.hh"
#include <map>
#include <vector>
#include <string>

class MyRunAction : public G4UserRunAction {
public:
    MyRunAction();
    virtual ~MyRunAction();

    virtual void BeginOfRunAction(const G4Run*) override;
    virtual void EndOfRunAction(const G4Run*) override;

    void AddEnergyDeposition(const G4String& volumeName, G4double edep);
    void AddTotalEnergyDeposition(G4double edep);  // New method to add total energy deposition

private:
    std::map<G4String, std::vector<G4double>> energyDepositionMap;  // Store energy depositions for each volume
    std::vector<G4double> totalEnergyDeposition;  // Store total energy deposition across all volumes
};

#endif
