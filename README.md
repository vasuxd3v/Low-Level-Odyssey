# low-level-systems
> binary internals, memory manipulation, x64 assembly, reverse engineering — documented as i go.

---

```
 ██████╗ ██████╗ ██╗    ██╗    ██████╗ ███████╗███████╗██████╗
 ██╔══██╗██╔══██╗██║    ██║    ██╔══██╗██╔════╝██╔════╝██╔══██╗
 ██████╔╝███████║██║ █╗ ██║    ██║  ██║█████╗  █████╗  ██████╔╝
 ██╔══██╗██╔══██║██║███╗██║    ██║  ██║██╔══╝  ██╔══╝  ██╔═══╝
 ██║  ██║██║  ██║╚███╔███╔╝    ██████╔╝███████╗███████╗██║
 ╚═╝  ╚═╝╚═╝  ╚═╝ ╚══╝╚══╝     ╚═════╝ ╚══════╝╚══════╝╚═╝
```

---

## what this is

a documented progression through low-level systems — from C memory internals down to raw binary, x64 assembly, and reverse engineering.

not a course. not a tutorial series. this is a working knowledge base — concepts i've internalized, code i've built from scratch, and notes i'd want if i were explaining this to someone who actually wants to understand what's happening at the hardware level, not just copy-paste their way through it.

if you're looking for beginner hand-holding, wrong repo.  
if you want to understand what the compiler is actually doing to your code, keep reading.

---

## the stack

```
┌─────────────────────────────────────────────┐
│  reverse engineering    IDA Free · x64dbg   │
├─────────────────────────────────────────────┤
│  windows internals      PE format · WinAPI  │
├─────────────────────────────────────────────┤
│  x64 assembly           Intel syntax · NASM │
├─────────────────────────────────────────────┤
│  memory internals       heap · stack · VM   │
├─────────────────────────────────────────────┤
│  deep C / C++           raw pointers · no   │
│                         training wheels     │
└─────────────────────────────────────────────┘
```

---

## what's in here

**memory & data representation** — endianness, integer overflow, two's complement, bit manipulation, pointer arithmetic. the stuff most programmers skip because it doesn't show up until something silently breaks.

**C / C++ internals** — stack frames, heap allocation, struct padding, alignment, function pointers. written in C++ but thinks in C. no STL crutches where they aren't needed.

**x64 assembly** — registers, calling conventions, control flow in asm, reading compiler output. the goal is to look at disassembly and read it the same way you read source code.

**memory internals** — virtual address spaces, page tables, how `malloc` actually works before it hands you a pointer. built a custom allocator. understand what `VirtualAlloc` is doing at the OS level.

**PE format & linking** — how a `.exe` is structured, what the loader does before `main` runs, import/export tables, relocations. the foundation for everything in the RE section.

**reverse engineering** — static analysis in IDA Free, annotated disassembly sessions, binary patching. code goes in as bytes, understanding comes out.

---

## tools

| tool | purpose |
|---|---|
| `gcc -O0 -S` | compile C to human-readable assembly |
| IDA Free | static analysis and disassembly |
| GDB / LLDB | runtime debugging |
| CFF Explorer | PE format inspection |
| PE-bear | PE header analysis |
| Valgrind | memory error detection |

---

## note on intent

everything here is for understanding how systems work at the lowest level — memory, binaries, execution. the skills overlap with security research, which means they're powerful and they're responsible.

this repo documents learning. it doesn't document attacks.

---

<div align="right">
<sub>built on a Mac · compiled with gcc · read in IDA</sub>
</div>
