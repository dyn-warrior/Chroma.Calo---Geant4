#include "MyHit.hh"

G4Allocator<MyHit> MyHitAllocator; // Define the allocator

MyHit::MyHit() : G4VHit(), edep(0.) {} // Define the constructor

MyHit::~MyHit() {}

MyHit::MyHit(const MyHit& right) : G4VHit() {
    edep = right.edep;
}

const MyHit& MyHit::operator=(const MyHit& right) {
    edep = right.edep;
    return *this;
}

G4int MyHit::operator==(const MyHit& right) const {
    return (this == &right) ? 1 : 0;
}
