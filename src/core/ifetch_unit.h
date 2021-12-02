#ifndef IFETCH_UNIT_H
#define IFETCH_UNIT_H

declare ifetch_unit {
	input newpc[32];
	func_in redirect(newpc);
	func_out push2();
}

#endif
