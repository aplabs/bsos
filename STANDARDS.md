Style and programming conventions for BSOS
==========================================

## Spacing and Tabs
* Use tabs, not spaces.
* One tab is four spaces. Configure your editor of choice to reflect this.
* Don't leave trailing spaces on lines.

## Assembly Files
* Use, at most, one level of indentation. Do *NOT* do this:

```
	mov ax, 5
	.mylbl:
		mov bx, 5
		.mynewlbl
			mov ax, ax ; nop
```

* Use descriptive labels and be explicit. Comments are encouraged on statements that are not obvious.

* Use the right register for the job.

* If your routine modifies the data within registers, make sure to push and pop said registers prior to and after modification.

## C and Other Languages
* For braces and indentation, follow Allman style. Braces go on separate lines.
* Explicit braces are not necessary in one-line conditionals and loops.
* Use `snake_case` for both variables and functions.
* Experimental functions should be preceeded by two underscores (e.g. `__my_experimental_func`).
* Preprocessor macros should be in `ALL_CAPS_SNAKE_CASE`.

## Documentation
* Document *ALL* source files. All source files should have a header following this rough standard:
```C
	/*	file_name.extension
		Short description of functionality.
		Name(s) of Author(s), date of writing
	*/
```

* Document *ALL* functions. Note return values, arguments, and potential pitfalls. For example:
```C
	/*	my_function
		Does x, y, and z.
		Returns an int containing the number of operations performed.
		Arguments: int* a, int* b, int* c, pointers to the integers to be used.
		Caveats: If a, b, or c is NULL, raises a segfault.
	*/
```

* Avoid commenting within functions unless absolutely necessary. A good function should be self-descriptive.

* If you modify a file, add yourself as an author in the header.
