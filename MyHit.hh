#ifndef MYHIT_HH
#define MYHIT_HH

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4ThreeVector.hh"
#include "G4Allocator.hh"

class MyHit : public G4VHit {
public:
    MyHit();
    virtual ~MyHit();
    MyHit(const MyHit&);
    const MyHit& operator=(const MyHit&);
    G4int operator==(const MyHit&) const;

    inline void* operator new(size_t);
    inline void operator delete(void*);

    void SetEdep(G4double de) { edep = de; }
    G4double GetEdep() const { return edep; }

private:
    G4double edep;
};

extern G4Allocator<MyHit> MyHitAllocator;

inline void* MyHit::operator new(size_t) {
    void* aHit;
    aHit = (void*)MyHitAllocator.MallocSingle();
    return aHit;
}

inline void MyHit::operator delete(void* aHit) {
    MyHitAllocator.FreeSingle((MyHit*)aHit);
}

#endif
