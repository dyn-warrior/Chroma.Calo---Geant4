#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "MyDetectorConstruction.hh"
#include "MyPrimaryGeneratorAction.hh"
#include "MyRunAction.hh"
#include "G4SDManager.hh"
#include "MySensitiveDetector.hh"
#include "FTFP_BERT.hh" // Include a predefined physics list

int main(int argc, char** argv) {
    G4RunManager* runManager = new G4RunManager();

    // Set mandatory initialization classes
    runManager->SetUserInitialization(new MyDetectorConstruction());
    runManager->SetUserInitialization(new FTFP_BERT()); // Set the physics list

    // Set user action classes
    runManager->SetUserAction(new MyPrimaryGeneratorAction());
    runManager->SetUserAction(new MyRunAction());

    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    MySensitiveDetector* sensitiveDetector = new MySensitiveDetector("SensitiveDetector");
    sdManager->AddNewDetector(sensitiveDetector);

    runManager->Initialize();

    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();

    G4UImanager* uiManager = G4UImanager::GetUIpointer();
    if (argc == 1) {
        G4UIExecutive* uiExecutive = new G4UIExecutive(argc, argv);
        uiManager->ApplyCommand("/control/macroPath /home/ratul/tank");
        uiManager->ApplyCommand("/control/execute init_vis.mac");
        uiExecutive->SessionStart();
        delete uiExecutive;
    } else {
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        uiManager->ApplyCommand(command + fileName);
    }

    delete visManager;
    delete runManager;

    return 0;
}