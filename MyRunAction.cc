#include "MyRunAction.hh"
#include "G4Run.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh" // Include this header for units

MyRunAction::MyRunAction() : G4UserRunAction() {
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->CreateH1("Volume1", "Energy deposition in Volume 1", 100, 0., 700*keV);
    analysisManager->CreateH1("Volume2", "Energy deposition in Volume 2", 100, 0., 700*keV);
    analysisManager->CreateH1("Volume3", "Energy deposition in Volume 3", 100, 0., 700*keV);
    analysisManager->CreateH1("Volume4", "Energy deposition in Volume 4", 100, 0., 700*keV);
    analysisManager->CreateH1("Volume5", "Energy deposition in Volume 5", 100, 0., 700*keV);
    analysisManager->CreateH1("TotalEnergy", "Total energy deposition in all volumes", 100, 0., 3500*keV); // New histogram
}


MyRunAction::~MyRunAction() {}

void MyRunAction::BeginOfRunAction(const G4Run*) {
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->OpenFile("output1.root");
}

void MyRunAction::EndOfRunAction(const G4Run*) {
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}
