#pragma once

#include <Dolphin/types.h>

#include <JSystem/JDrama/JDRGraphics.hxx>
#include <JSystem/JGeometry/JGMVec.hxx>
#include <JSystem/JSupport/JSUMemoryStream.hxx>
#include <SMS/Enemy/SpineBase.hxx>
#include <SMS/M3DUtil/LodAnm.hxx>
#include <SMS/M3DUtil/MActor.hxx>
#include <SMS/M3DUtil/MActorKeeper.hxx>
#include <SMS/MSound/MAnmSound.hxx>
#include <SMS/Manager/LiveManager.hxx>
#include <SMS/Manager/MapCollisionManager.hxx>
#include <SMS/Map/BGCheck.hxx>
#include <SMS/MarioUtil/RidingInfo.hxx>
#include <SMS/Strategic/TakeActor.hxx>

class TLiveActor : public TTakeActor {
public:
    TLiveActor(const char *);
    virtual ~TLiveActor();

    virtual void load(JSUMemoryInputStream &) override;
    virtual void perform(u32, JDrama::TGraphics *) override;
    virtual bool receiveMessage(THitActor *, u32) override;
    virtual Mtx44 *getTakingMtx() override;
    virtual bool belongToGround() const;
    virtual Mtx44 *getRootJointMtx() const;
    virtual void init(TLiveManager *);
    virtual void calcRootMatrix();
    virtual void setGroundCollision();
    virtual void control();
    virtual void bind();
    virtual void moveObject();
    virtual void requestShadow();
    virtual void drawObject(JDrama::TGraphics *);
    virtual void performOnlyDraw(u32, JDrama::TGraphics *);
    virtual u32 getShadowType();
    virtual void kill();
    virtual f32 getGravityY() const;
    virtual bool hasMapCollision() const;
    virtual TVec3f getFocalPoint() const;
    virtual void updateAnmSound();
    virtual const char **getBasNameTable() const;

    MActor *getMActor() const;
    void stopAnmSound();
    void setCurAnmSound();
    void setAnmSound(const char *);
    void initAnmSound();
    void getJointTransByIndex(int, TVec3f *) const;
    TVec3f calcVelocityToJumpToY(const TVec3f &, f32, f32) const;
    void initLodAnm(const TLodAnmIndex *, int, f32);
    J3DModel *getModel() const;
    void calcRideMomentum();
    void calcRidePos();

    TLiveManager *mLiveManager;   // 0x0070
    MActor *mActorData;           // 0x0074
    TMActorKeeper *mActorKeeper;  // 0x0078
    u16 mActorIndex;              // _7C
    MAnmSound *mAnmSound;         // _80
    char *mBasName;               // _84
    u32 *_88;
    TSpineBase<TLiveActor> *mSpineBase;  // 0x008C
    u32 _90;                             // 0x0090
    TVec3f mPositionalVelocity;          // 0x0094
    TVec3f mRotationalVelocity;          // 0x00A0
    TVec3f mSpeed;                       // 0x00AC
    f32 mShadowRadius;                   // 0x00B8
    f32 mMaxSpeed;                       // 0x00BC
    f32 _C0;                             // 0x00C0
    const TBGCheckData *mFloorBelow;     // 0x00C4
    f32 mGroundY;                        // 0x00C8
    f32 mGravity;                        // 0x00CC
    u32 _D0;
    TRidingInfo mRidingInfo;  // _D4
    f32 _E4;
    u8 _E8;
    TMapCollisionManager *mCollisionManager;  // _EC

    struct {
        bool unk_80000000               : 1;
        bool unk_40000000               : 1;
        bool mIsNPCThrowIgnored         : 1;
        bool mIsNPCReleasingFromTaken   : 1;
        bool mIsNPCRecoveringFromSunken : 1;
        bool mIsNPCMadForced            : 1;
        bool mIsNPCMad                  : 1;
        bool mIsNPCCulled               : 1;
        bool mIsSunken                  : 1;
        bool mIsSinking                 : 1;
        bool mIsTurnClockwise           : 1;
        bool mCanBeTaken                : 1;
        bool mIsTalking                 : 1;
        bool mIsLongTalkInvariant       : 1;
        bool mCanBeTalked               : 1;
        bool mIsChildTanooki            : 1;
        bool mIsResetToPosition         : 1;
        bool mIsAsleep                  : 1;
        bool unk_2000                   : 1;
        bool unk_1000                   : 1;
        bool mIsResetToGraph            : 1;
        bool mIsShadowForced            : 1;
        bool mInAreaCube                : 1;
        bool mIsClippable               : 1;
        bool mIsAirborne                : 1;
        bool mIsDying                   : 1;
        bool unk_20                     : 1;
        bool mIsBound                   : 1;
        bool mHasShadow                 : 1;
        bool mIsClipped                 : 1;
        bool mIsHidden                  : 1;
        bool mIsDead                    : 1;
    } mStateFlags;
};