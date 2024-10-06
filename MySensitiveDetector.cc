/*#include "MySensitiveDetector.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4SystemOfUnits.hh"
#include "G4AnalysisManager.hh"

MySensitiveDetector::MySensitiveDetector(const G4String& name) : G4VSensitiveDetector(name) {}

MySensitiveDetector::~MySensitiveDetector() {}

G4bool MySensitiveDetector::ProcessHits(G4Step* aStep, G4TouchableHistory*) {
    G4double edep = aStep->GetTotalEnergyDeposit();
    if (edep == 0.) return false;

    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    //G4int volumeID = aStep->GetPreStepPoint()->GetTouchableHandle()->GetCopyNumber();
    G4String volumeName = astep->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();
   /* analysisManager->FillH1(Volume1, edep);
    analysisManager->FillH1(Volume2, edep);
    analysisManager->FillH1(Volume3, edep);
    analysisManager->FillH1(Volume4, edep);
    analysisManager->FillH1(Volume5, edep);*/
 /*   if (volumeName == "Volume1") {
    analysisManager->FillH1(0, edep);
} else if (volumeName == "Volume2") {
    analysisManager->FillH1(1, edep);
} else if (volumeName == "Volume3") {
    analysisManager->FillH1(2, edep);
} else if (volumeName == "Volume4") {
    analysisManager->FillH1(3, edep);
} else if (volumeName == "Volume5") {
    analysisManager->FillH1(4, edep);
}

    return true;
}
*/
/*#include "MySensitiveDetector.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"

MySensitiveDetector::MySensitiveDetector(const G4String& name)
    : G4VSensitiveDetector(name) {
    collectionName.insert("HitsCollection");
}

MySensitiveDetector::~MySensitiveDetector() {}

void MySensitiveDetector::Initialize(G4HCofThisEvent* hce) {
    fHitsCollection = new G4THitsCollection<G4double>(SensitiveDetectorName, collectionName[0]);
    G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    hce->AddHitsCollection(hcID, fHitsCollection);
}

G4bool MySensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory* history) {
    G4double edep = step->GetTotalEnergyDeposit();
    if (edep == 0.) return false;

    fHitsCollection->insert(new G4double(edep));
    return true;
}

void MySensitiveDetector::EndOfEvent(G4HCofThisEvent* hce) {
    // Optionally, you can add code here to process the hits at the end of the event
}*/

/*#include "MySensitiveDetector.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4AnalysisManager.hh"

MySensitiveDetector::MySensitiveDetector(const G4String& name)
    : G4VSensitiveDetector(name) {
    collectionName.insert("HitsCollection");
}

MySensitiveDetector::~MySensitiveDetector() {}

void MySensitiveDetector::Initialize(G4HCofThisEvent* hce) {
    fHitsCollection = new G4THitsCollection<G4double>(SensitiveDetectorName, collectionName[0]);
    G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    hce->AddHitsCollection(hcID, fHitsCollection);
}

G4bool MySensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory* history) {
    G4double edep = step->GetTotalEnergyDeposit();
    if (edep == 0.) return false;

    // Get volume name
    G4String volumeName = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();

    // Get analysis manager
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    // Fill histograms based on volume name
    if (volumeName == "GAGG") {
        analysisManager->FillH1(0, edep);
    } else if (volumeName == "PWO") {
        analysisManager->FillH1(1, edep);
    } else if (volumeName == "BGO") {
        analysisManager->FillH1(2, edep);
    } else if (volumeName == "PWO4") {
        analysisManager->FillH1(3, edep);
    } else if (volumeName == "LYSO") {
        analysisManager->FillH1(4, edep);
    }

    fHitsCollection->insert(new G4double(edep));
    return true;
}

void MySensitiveDetector::EndOfEvent(G4HCofThisEvent* hce) {
    // Optionally, you can add code here to process the hits at the end of the event
}*/


#include "MySensitiveDetector.hh"
#include "G4Step.hh"
#include "G4TouchableHistory.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4AnalysisManager.hh"
#include "MyHit.hh"

MySensitiveDetector::MySensitiveDetector(const G4String& name)
    : G4VSensitiveDetector(name) {
    collectionName.insert("HitsCollection");
}

MySensitiveDetector::~MySensitiveDetector() {}

void MySensitiveDetector::Initialize(G4HCofThisEvent* hce) {
    fHitsCollection = new G4THitsCollection<MyHit>(SensitiveDetectorName, collectionName[0]);
    G4int hcID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
    hce->AddHitsCollection(hcID, fHitsCollection);
}

G4bool MySensitiveDetector::ProcessHits(G4Step* step, G4TouchableHistory* history) {
    G4double edep = step->GetTotalEnergyDeposit();
    if (edep == 0.) return false;

    MyHit* newHit = new MyHit();
    newHit->SetEdep(edep);

    // Get volume name
    G4String volumeName = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName();

    // Get analysis manager
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    // Fill histograms based on volume name
    if (volumeName == "GAGG") {
        analysisManager->FillH1(0, edep);
    } else if (volumeName == "PWO") {
        analysisManager->FillH1(1, edep);
    } else if (volumeName == "BGO") {
        analysisManager->FillH1(2, edep);
    } else if (volumeName == "PWO4") {
        analysisManager->FillH1(3, edep);
    } else if (volumeName == "LYSO") {
        analysisManager->FillH1(4, edep);
    }
  // Fill the total energy deposition histogram
    analysisManager->FillH1(5, edep);

    fHitsCollection->insert(newHit);
    return true;
}

void MySensitiveDetector::EndOfEvent(G4HCofThisEvent* hce) {
    // Optionally, you can add code here to process the hits at the end of the event
}
