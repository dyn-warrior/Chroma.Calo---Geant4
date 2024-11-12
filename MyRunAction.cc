#include "MyRunAction.hh"
#include "G4Run.hh"
#include "G4AnalysisManager.hh"
#include "G4SystemOfUnits.hh"
#include "TFile.h"
#include "TH1D.h"
#include "TCanvas.h"

MyRunAction::MyRunAction() : G4UserRunAction() {}

MyRunAction::~MyRunAction() {}

void MyRunAction::BeginOfRunAction(const G4Run*) {
    // Clear the map at the beginning of the run
    energyDepositionMap.clear();
    totalEnergyDeposition.clear();
}

void MyRunAction::AddEnergyDeposition(const G4String& volumeName, G4double edep) {
    energyDepositionMap[volumeName].push_back(edep);  // Store energy deposition for the volume
}

void MyRunAction::AddTotalEnergyDeposition(G4double edep) {
    totalEnergyDeposition.push_back(edep);  // Store total energy deposition
}

void MyRunAction::EndOfRunAction(const G4Run*) {
    // Open ROOT file in "UPDATE" mode to add new data without deleting existing data
    TFile* file = new TFile("energyDeposition7.root", "UPDATE");

    // Create histograms for each volume
    for (const auto& entry : energyDepositionMap) {
        const G4String& volumeName = entry.first;
        const std::vector<G4double>& energyDepositions = entry.second;

        // Retrieve or create a histogram for the volume
        TH1D* hist = dynamic_cast<TH1D*>(file->Get(volumeName.c_str()));
        if (!hist) {
            hist = new TH1D(volumeName.c_str(), ("Energy Deposition in " + volumeName).c_str(), 100, 0, 10);  // Adjust bins and range as needed
        }

        // Fill the histogram with energy deposition data
        for (const auto& edep : energyDepositions) {
            hist->Fill(edep / CLHEP::GeV);  // Convert energy to GeV
        }

        // Write the histogram to the ROOT file
        hist->Write("", TObject::kOverwrite);  // Overwrite the existing histogram
    }

    // Create or update the histogram for total energy deposition
    TH1D* totalHist = dynamic_cast<TH1D*>(file->Get("TotalEnergyDeposition"));
    if (!totalHist) {
        totalHist = new TH1D("TotalEnergyDeposition", "Total Energy Deposition", 100, 0, 50);  // Adjust bins and range as needed
    }

    // Fill the histogram with total energy deposition data
    for (const auto& edep : totalEnergyDeposition) {
        totalHist->Fill(edep / CLHEP::GeV);  // Convert energy to GeV
    }

    // Write the total energy histogram to the ROOT file
    totalHist->Write("", TObject::kOverwrite);  // Overwrite the existing histogram

    // Close the ROOT file
    file->Close();
}
