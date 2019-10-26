/*
 * gbs_internal.h
 *
 *  Created on: 21 May 2018
 *      Author: CoolerMaster
 */

#ifndef INCLUDE_GBA_GBS_INTERNAL_H_
#define INCLUDE_GBA_GBS_INTERNAL_H_

#include "gba/gba.h"

#define SetOctave0 0xD8
#define SetOctave7 0xD0

enum SoundEngineCommands
{
	SetNoteAttributesAndLength,
	SetKeyShift,
	SetTempo,
	SetDutyCycle,
	SetNoteAttributes,
	Arpeggiate,
	SetDutyCycle2,
	Portamento,
	PitchBend,
	SetModulation,
	E2,
	E3,
	E4,
	SetChannelVolume,
	SetTone,
	E7,
	E8,
	E9,
	EA,
	EB,
	EC,
	ED,
	EE,
	Pan,
	F0,
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	SetHostTempo,
	JumpIf,
	Jump,
	Goto,
	Call,
	End
};

enum GBPStatusFlags { ModulationActivation, ModulationStatus, PortamentoActivation, PitchBendActivation, ArpeggiationActivation, ArpeggiationStatus, NumGBPEngineFlags };

struct ToneTrack
{
	u8 flags;
	u8 noteLength1;
    u8 patternLevel:4;
    u8 trackID:4;
	u8 loopCounter;
	u8 noteLength2;
	u8 currentOctave;
	u8 velocity;
	u8 loopCounter2;
	u16 pitch;
	s8 keyShift;
	u8 frameDelay;
	u16 tone;
	s8 pitchBendRate;
	u8 currentVoice;
	u8 channelVolume;
	u8 fadeSpeed;
	u8 unk_counter;
	u8 arpeggiationVoice;
	u8 pan;
	u8 modulationCountdown;
	u8 modulationDelay;
	u8 modulationMode;
	u8 modulationDepth;
	u8 modulationSpeedDelay;
	u8 modulationSpeed;
	u8 arpeggiationDelayCount;
	u8 arpeggiationCountdown;
	u8 portamentoCountdown;
	u8 portamentoDelay;
	u8 portamentoTarget;
    struct SoundChannel *chan;
	u8 portamentoSpeedDelay;
	u8 portamentoSpeed;
	bool8 statusFlags[NumGBPEngineFlags];
	u8 fadeDirection;
	u8 padding[19];
	u8* nextInstruction;
	u8* returnLocation;
	u8 secondaryPadding[8];
};

struct WaveTrack
{
	u8 flags;
	u8 noteLength1;
    u8 patternLevel:4;
    u8 gbsIdentifier:4;
	u8 loopCounter;
	u8 noteLength2;
	u8 currentOctave;
	u8 velocity;
	u8 loopCounter2;
	u16 pitch;
	s8 keyShift;
	u8 frameDelay;
	u16 tone;
	s8 pitchBendRate;
	u8 currentVoice;
	u8 channelVolume;
	u8 fadeSpeed;
	u8 unk_counter;
	u8 padding;
	u8 pan;
	u8 modulationCountdown;
	u8 modulationDelay;
	u8 modulationMode;
	u8 modulationDepth;
	u8 modulationSpeedDelay;
	u8 modulationSpeed;
	u8 secondaryPadding[2];
	u8 portamentoCountdown;
	u8 portamentoDelay;
	u8 portamentoTarget;
    struct SoundChannel *chan;
	u8 portamentoSpeedDelay;
	u8 portamentoSpeed;
	bool8 statusFlags[NumGBPEngineFlags];
	u8 tertiaryPadding[20];
	u8* nextInstruction;
	u8* returnLocation;
	u8 quaternaryPadding[8];
};

struct NoiseTrack
{
	u8 flags;
	u8 noteLength1;
    u8 patternLevel:4;
    u8 gbsIdentifier:4;
	u8 loopCounter;
	u8 noteLength2;
	u8 currentOctave;
	u8 velocity;
	u8 loopCounter2;
	u16 pitch;
	s8 keyShift;
	u8 frameDelay;
	u16 tone;
	s8 pitchBendRate;
	u8 noiseSet;
	u8 channelVolume;
	u8 fadeSpeed;
	u8 unk_counter;
	u8 noiseFrameDelay;
	u8 pan;			   // 0x14
	u8* samplePointer; // 0x18
	bool8 noiseActive; // 0x1C
	u8 secondaryPadding[3];
    struct SoundChannel *chan;
	u8 tertiaryiPadding[2];
	bool8 statusFlags[NumGBPEngineFlags];
	u8 tertiaryPadding[24];
	u8* nextInstruction;
	u8* returnLocation;
	u8 quaternaryPadding[8];
};

#endif /* INCLUDE_GBA_GBS_INTERNAL_H_ */
