# Traffic Signal State Machine

The traffic signal operates as a finite state machine:

States:
- GREEN
- YELLOW
- RED

State Transitions:
- GREEN → YELLOW
- YELLOW → RED
- RED → GREEN (for next direction)

The master controller controls all transitions and ensures that no two conflicting directions enter the GREEN state simultaneously.
