PROGRAM QueueTest(INPUT, OUTPUT);
USES QUEUE;

VAR
  Num: INTEGER;

BEGIN
  WRITELN('queue Empty: ', IsQueueEmpty());
  Push(5);
  Push(4);
  Push(3);
  Push(2);
  Push(1);
  Num := Pop();
  WRITELN(Num);
  Num := Pop();
  WRITELN(Num);
  Num := Pop();
  WRITELN(Num);
  Num := Pop();
  WRITELN(Num);
  Num := Pop();
  WRITELN(Num);
  WRITELN('queue Empty: ', IsQueueEmpty());
  Push(1);
  WRITELN('queue Empty: ', IsQueueEmpty());
  Num := Pop();
  WRITELN(Num);
END.
