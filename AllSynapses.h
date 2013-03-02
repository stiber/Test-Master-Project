
#pragma once

#ifndef _ALLSYNAPSES_H_
#define _ALLSYNAPSES_H_

#include "global.h"
#ifdef _WIN32
typedef unsigned _int8 uint8_t;
#endif

struct AllSynapses
{
public:
	//! The coordinates of the summation point.
    	Coordinate summationCoord[];

	//! The weight (scaling factor, strength, maximal amplitude) of the synapse.
    	FLOAT W[];

    	//! This synapse's summation point's address.
    	FLOAT *summationPoint[];

    	//! The location of the synapse.
    	Coordinate synapseCoord[];

    	//! The time step size.
    	FLOAT deltaT[];

    	//! The post-synaptic response is the result of whatever computation is going on in the synapse.
    	FLOAT psr[];
	//! The decay for the psr.
    	FLOAT decay[];
   	//! The synaptic transmission delay, descretized into time steps.
	int total_delay[]; 
#define BYTES_OF_DELAYQUEUE         ( sizeof(uint32_t) / sizeof(uint8_t) )
#define LENGTH_OF_DELAYQUEUE        ( BYTES_OF_DELAYQUEUE * 8 )
    	//! The delayed queue
    	uint32_t delayQueue[][1];
    	//! The index indicating the current time slot in the delayed queue
    	int delayIdx[];
    	//! Length of the delayed queue
    	int ldelayQueue[];
    	//! Synapse type
    	synapseType type[];

	// NETWORK MODEL VARIABLES NMV-BEGIN {
	    	//! The synaptic time constant \f$\tau\f$ [units=sec; range=(0,100)].
	    	FLOAT tau[];

	    	// dynamic synapse vars...........
	    	//! The time varying state variable \f$r\f$ for depression.
	    	FLOAT r[];
	   	 //! The time varying state variable \f$u\f$ for facilitation.
	    	FLOAT u[];
	    	//! The time constant of the depression of the dynamic synapse [range=(0,10); units=sec].
	    	FLOAT D[];
	    	//! The use parameter of the dynamic synapse [range=(1e-5,1)].
	    	FLOAT U[];
	    	//! The time constant of the facilitation of the dynamic synapse [range=(0,10); units=sec].
	    	FLOAT F[];
	    	//! The time of the last spike.
		uint64_t lastSpike;
	// } NMV-END
};

#endif
