#include "MySensitiveDetector.hh"
#include "MyRunAction.hh"
#include "G4RunManager.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"

MySensitiveDetector::MySensitiveDetector(const G4String& name, const G4String& hitsCollectionName)
  : G4VSensitiveDetector(name), fTotalEnergyDep(0.0) {}

MySensitiveDetector::~MySensitiveDetector() {}

void MySensitiveDetector::Initialize(G4HCofThisEvent*) {
    fTotalEnergyDep = 0.0;  // Reset total energy deposition
    fEnergyDepMap.clear();  // Clear energy deposition map
}

G4bool MySensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory*) {
    G4double edep = step->GetTotalEnergyDeposit();
    if (edep == 0) return false;

    fTotalEnergyDep += edep;  // Accumulate total energy deposition

    // Get the volume name
    G4String volumeName = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();

    // Accumulate energy deposition for the volume
    fEnergyDepMap[volumeName] += edep;

    return true;
}

void MySensitiveDetector::EndOfEvent(G4HCofThisEvent*) {
    // Get the MyRunAction and register the energy deposition for each volume
    MyRunAction* runAction = const_cast<MyRunAction*>(static_cast<const MyRunAction*>(G4RunManager::GetRunManager()->GetUserRunAction()));
    for (const auto& entry : fEnergyDepMap) {
        runAction->AddEnergyDeposition(entry.first, entry.second);  // Register energy for each volume
    }
    runAction->AddTotalEnergyDeposition(fTotalEnergyDep);  // Register total energy deposition
}
