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
// $Id: SCIBARRunAction.hh 69561 2013-05-08 12:25:56Z gcosmo $
//
/// \file optical/wls/include/SCIBARRunAction.hh
/// \brief Definition of the SCIBARRunAction class
//

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef SCIBARRunAction_h
#define SCIBARRunAction_h 1

#include "globals.hh"

#include "G4UserRunAction.hh"

class G4Run;
class SCIBARHistoManager;//newadd

class SCIBARRunActionMessenger;

class SCIBARRunAction : public G4UserRunAction
{
  public:

    //SCIBARRunAction();
    SCIBARRunAction(SCIBARHistoManager*);//newadd
    virtual ~SCIBARRunAction();

  public:

    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);

    void  SetRndmFreq(G4int val) { fSaveRndm = val; }
    G4int GetRndmFreq()          { return fSaveRndm; }
    void fillPerEvent(G4double, G4double);//newadd
    inline void SetAutoSeed (const G4bool val) { fAutoSeed = val; }

  private:
 
    SCIBARRunActionMessenger* fRunMessenger;
    SCIBARHistoManager* fHistoManager;//newadd
    G4double fSumEDep, fSum2EDep;//newadd
    G4double fSumLDep, fSum2LDep;//newadd
    G4int fSaveRndm;
    G4bool fAutoSeed;

};

#endif
