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
// $Id: SCIBARPhotonDetHit.cc 70825 2013-06-06 08:29:26Z gcosmo $
//
/// \file optical/wls/src/SCIBARPhotonDetHit.cc
/// \brief Implementation of the SCIBARPhotonDetHit class
//
//
#include "SCIBARPhotonDetHit.hh"

G4ThreadLocal G4Allocator<SCIBARPhotonDetHit>* SCIBARPhotonDetHitAllocator=0;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SCIBARPhotonDetHit::SCIBARPhotonDetHit()
{
  fArrivalTime = 0.;
  fPosArrive   = G4ThreeVector(0., 0., 0.);
  fPosExit     = G4ThreeVector(0., 0., 0.);
    fenergyDeposit = 0.;//newadd3
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SCIBARPhotonDetHit::SCIBARPhotonDetHit(G4ThreeVector pExit,
                                 G4ThreeVector pArrive,
                                 G4double pTime, G4double pEnergyDeposit)
{
  fPosExit     = pExit;
  fPosArrive   = pArrive;
  fArrivalTime = pTime;
    fenergyDeposit = pEnergyDeposit;//newadd3
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SCIBARPhotonDetHit::~SCIBARPhotonDetHit() { }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SCIBARPhotonDetHit::SCIBARPhotonDetHit(const SCIBARPhotonDetHit &right)
  : G4VHit()
{
  *this = right;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

const SCIBARPhotonDetHit& SCIBARPhotonDetHit::operator=(const SCIBARPhotonDetHit &right)
{
  fPosExit     = right.fPosExit;
  fPosArrive   = right.fPosArrive;
  fArrivalTime = right.fArrivalTime;
    fenergyDeposit = right.fenergyDeposit;//newadd3

  return *this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4int SCIBARPhotonDetHit::operator==(const SCIBARPhotonDetHit& right) const
{
  return fPosExit     == right.fPosExit    &&
         fPosArrive   == right.fPosArrive  &&
         fArrivalTime == right.fArrivalTime &&
        fenergyDeposit == right.fenergyDeposit;//newadd3
}
