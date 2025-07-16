# RTOS Task Scheduler Simulation

🎯 **Simulates a simple RTOS task scheduler in C, with round-robin and priority-based scheduling.**
Runs entirely on a laptop — no hardware needed — to demonstrate embedded software concepts.

---

##  Features
✅ Simulates multiple tasks (as functions).  
✅ Supports two scheduling algorithms:
- Round-Robin
- Priority-Based
✅ Simulates context switching & time slices.  
✅ Written in pure C, portable to any platform with a C compiler.

---

## How to Run

### 🛠 Prerequisites
- C compiler (`gcc`, `clang`, etc.)
- Git (optional, for version control)

###  Build
On Linux/Mac:
```bash
gcc rtos_scheduler.c -o rtos_scheduler
./rtos_scheduler


