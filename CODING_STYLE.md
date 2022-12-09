# Coding Style Guide

## General rules

## File naming

- Use snake case of its module name.
- Extension of NSL module should be '.nsl'.
- Extension of header of NSL module should be '.h'.
- Extension of parameterilze module which included from NSL module should be '.inc'.

### Indentation

- Tabs should not be used, and expanded to 4 spaces.

### Identifier

- Identifer should be snakecase.
- If some specification specifies signal name, it can be used, however following rules below is better.

### Module

- Use snake case and corresponds to its file name.
- If module name is abbereviations, module name can be follow expression of abbereviations, in such case file name must be corresponds to modulename.

### Macro name

- Macro name should be all uppercase and separated by '_'.
- Macro should be defined in header file.

### Struct name

- Name of structure should be snake case suffixed with '_t'.
- `SIZEOF_<sturct name>` should be exported as macro for its size in decimal.

### Input signals

- Input signal name should suffixed with '_i'.

### Output signals

- Output signal name should suffixed with '_o'.

### Inout

- Inout signals should not be used.
- Use separete input and output.

### func\_in

- Name of func\_in should be prefixed with 'req_'.
- Name of func\_in response(signal for return value) should be prefixed with 'rsp_<func_in_name>_'.
- Name of func\_in arguments also should be prefixed with 'req_<func_in_name>_'
- If no argument is present, '()' can be ommited.

#### Declaration of func\_in

```
declare mod {
	input req_arg0;
	input req_arg1;
	output rsp_read_data;
	func_in req_read(req_read_arg0, req_read_arg1): rsp_read_data;
}
```

### func\_out

- Name of func\_out should be prefixed with 'req_'.
- Name of func\_out response(signal for return value) should be prefixed with 'rsp_<func_out_name>_'.
- Name of func\_out arguments also should be prefixed with 'req_<func_out_name>_'
- If no argument is present, '()' can be ommited.

#### Declaration of func\_in

```
declare mod {
	output req_arg0;
	output req_arg1;
	input rsp_read_data;
	func_out req_read(req_read_arg0, req_read_arg1): rsp_read_data;
}
```

### Validity of Input/Output value

- input/output signals which are not argument or return signals of func\_in/func\_out, it is valid through clock cycles.
- if input/output signals which are argument or return signals of func\_in/func\_out, it is only valid on corresponding `func` is valid. 

### Constant value

- Constant can be used in any form valid, if width of constant can be determined by compiler, otherwise should be binary or hex with size specifier.
- Magic number should not be used, instead use macro.

### Integer

- Integer variable can be declared as 'i_' for re-useable module-wide integer.

### Variable

- Variable cannot be used, since order of assignment matters and it is hard to debug.

### Module internal signals

- Internal signals can be used with or without any prefix or suffix.
- If they are only valid in state/proc/func it should be prefixed with its state/proc/func followed by '_'.
- Signals which refered from outside of state/proc/func, it should be declared within module level, otherwise it should be kept to state/proc/func local.

### Proc

- Proc name can be used with or without any prefix or suffix.
- If proc is invoked from outside of proc, it should use '\.invoke()'.
- If proc is finished from outside of proc, it should use '\.finish()'.
- Arguments of proc should be declared in the order given to proc.
- Arguments of proc should be prefixed with '<proc_name>_' and be valid on proc is valid.
- Signals of proc should be prefixed with '<proc_name>_' and be valid on proc is valid.
- Argument or Singlas in proc is valid on proc is valid.

### State

- State can be used with or without any prefix or suffix.
- Signals of state should be prefixed with '<state_name>_' and be valid on state is valid.
- Argument or Singlas in state is valid on state is valid.

### func\_self

- func\_self can be used with or without any prefix or suffix.
- Arguments of func_self should be declared in the order given to func_self.
- Arguments of func_self should be prefixed with '<func_self_name>_' and be valid on func_self is valid.
- Signals of func_self should be prefixed with '<func_self_name>_' and be valid on func_self is valid.
- Argument or Singlas in func_self is valid on func_self is valid.

