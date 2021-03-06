//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file analysis/AnaEx01/include/SCIBARHistoManager.hh
/// \brief Definition of the SCIBARHistoManager class
//
//
// $Id: SCIBARHistoManager.hh 92318 2015-08-27 14:49:47Z gcosmo $
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo...... 

#ifndef SCIBARHistoManager_h
#define SCIBARHistoManager_h 1

#include "globals.hh"

#include "g4root.hh"
//#include "g4csv.hh"
//#include "g4xml.hh"
//#include "g4hbook.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class SCIBARHistoManager
{
  public:
    SCIBARHistoManager();
   ~SCIBARHistoManager();

    void Book();
    void Save();
    
    void FillHisto(G4int id, G4double e, G4double weight = 1.0);
    void Normalize(G4int id, G4double fac);    

    /*void FillNtuple(G4double EnergyAbs, G4double EnergyGap,
                    G4double TrackLAbs, G4double TrackLGap);*/
    void FillNtuple(G4double EnergyDep, G4double TrackLDep);
    void FillPrimTrack(G4double x, G4double y, G4double z, G4double pz, G4double theta, G4int nphotopass, G4int nphotofail, G4int nphotoscint, G4int nphotocheren, G4double enscint, G4double encheren);
    void PrintStatistic();        
    
  private:
    G4bool fFactoryOn;    
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

