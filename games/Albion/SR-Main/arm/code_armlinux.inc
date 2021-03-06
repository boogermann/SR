@@
@@  Copyright (C) 2016 Roman Pauer
@@
@@  Permission is hereby granted, free of charge, to any person obtaining a copy of
@@  this software and associated documentation files (the "Software"), to deal in
@@  the Software without restriction, including without limitation the rights to
@@  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
@@  of the Software, and to permit persons to whom the Software is furnished to do
@@  so, subject to the following conditions:
@@
@@  The above copyright notice and this permission notice shall be included in all
@@  copies or substantial portions of the Software.
@@
@@  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
@@  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
@@  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
@@  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
@@  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
@@  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
@@  SOFTWARE.
@@

.extern stderr

print_dialog_end:

    @pushad
    PUSHAD

    @push dword dialog_end
    LDR tmp1, =dialog_end
    stmfd esp!, {tmp1}

    @push dword [stderr]
    LDR tmp1, =stderr
    ldr tmp1, [tmp1]
    stmfd esp!, {tmp1}

    @call SR_fprintf
    ADR tmp1, print_dialog_end_after_call
    stmfd esp!, {tmp1}
    b SR_fprintf
    .ltorg
    print_dialog_end_after_call:

    @add esp, 2*4
    add esp, esp, #(2*4)

    @popad
    POPAD

    @retn
    ldmfd esp!, {eip}

print_eax:

    @pushad
    PUSHAD

    @push eax
    stmfd esp!, {eax}
    @push dword eax_value
    LDR tmp1, =eax_value
    stmfd esp!, {tmp1}

    @push dword [stderr]
    LDR tmp1, =stderr
    ldr tmp1, [tmp1]
    stmfd esp!, {tmp1}

    @call SR_fprintf
    ADR tmp1, print_eax_after_call
    stmfd esp!, {tmp1}
    b SR_fprintf
    .ltorg
    print_eax_after_call:

    @add esp, 3*4
    add esp, esp, #(3*4)

    @popad
    POPAD

    @retn
    ldmfd esp!, {eip}

print_string_eax:

    @pushad
    PUSHAD

    @push eax
    stmfd esp!, {eax}
    @push dword loc_130909
    LDR tmp1, =loc_130909
    stmfd esp!, {tmp1}

    @push dword [stderr]
    LDR tmp1, =stderr
    ldr tmp1, [tmp1]
    stmfd esp!, {tmp1}

    @call SR_fprintf
    ADR tmp1, print_string_eax_after_call
    stmfd esp!, {tmp1}
    b SR_fprintf
    .ltorg
    print_string_eax_after_call:

    @add esp, 3*4
    add esp, esp, #(3*4)

    @popad
    POPAD

    @retn
    ldmfd esp!, {eip}

