#ifndef BRANCH_PREDICTOR_H
#define BRANCH_PREDICTOR_H

declare branch_predictor {
	input req_predict0_pc[32];
	output rsp_predict0_pred;
	output rsp_predict0_target[32];
	func_in req_predict0(req_predict0_pc);
	input req_predict1_pc[32];
	output rsp_predict1_pred;
	output rsp_predict1_target[32];
	func_in req_predict1(req_predict1_pc);
	input req_update_predict0_pc[32];
	input req_update_predict0_target[32];
	func_in req_update_predict0(req_update_predict0_pc, req_update_predict0_target);
	input req_update_predict1_pc[32];
	input req_update_predict1_target[32];
	func_in req_update_predict1(req_update_predict1_pc, req_update_predict1_target);
	func_in req_flush();
}

#endif
