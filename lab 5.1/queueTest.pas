PROGRAM QueueTest(INPUT, OUTPUT);
USES QUEUE;

VAR
  Num: INTEGER;

BEGIN
  Push(10, 3);
  Push(15, 1);
  Push(17, 1);
  Push(5, 1);
  Push(7, 1);
  WRITELN(Pop());
  ChangePriority(17, 2);
  WRITELN(Pop());
  ChangePriority(17, 2);
END.
