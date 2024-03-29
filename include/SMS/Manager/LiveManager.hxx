#pragma once

#include <JSystem/JDrama/JDRGraphics.hxx>
#include <SMS/Manager/ObjManager.hxx>
#include <SMS/SPC/SpcBinary.hxx>

class TLiveActor;

class TLiveManager : public TObjManager {
public:
    TLiveManager(const char *);
    virtual ~TLiveManager();

    virtual void load(JSUMemoryInputStream &);
    virtual void perform(u32, JDrama::TGraphics *);
    virtual void clipActors(JDrama::TGraphics *);
    virtual void setFlagOutOfCube();
    virtual void createSpcBinary();
    virtual bool hasMapCollision() const;

    void clipActorsAux(JDrama::TGraphics *, f32, f32);
    void getActorByFlag(u32 flag) const;
    void manageActor(TLiveActor *actor);

    TSpcBinary *mSpcBinary;  // _34
};