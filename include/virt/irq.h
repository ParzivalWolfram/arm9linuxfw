#pragma once

#include "common.h"

#define VIRQ_MAX	128

enum {
	VIRQ_VQUEUE = 0,
	VIRQ_CONFIG = 1,
	VIRQ_MODES
};

/** resets all pending virtual interrupts */
void virtIrqReset(void);

/**
 * marks a virq as pending and automatically triggers SYNC
 * must be called from atomic context
 */
u32 virtIrqSet(u32 devId, uint mode);

/** retrieves a virq bank and acknowledges them - thread safe */
u32 virtIrqGet(u32 bankId, uint mode);

/** triggers a synchronization hardware IRQ */
void virtIrqSync(void);
