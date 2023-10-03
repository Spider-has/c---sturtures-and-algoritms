PROGRAM StackTest(INPUT, OUTPUT);
USES
  Stack;

VAR
  A: DataType;
BEGIN
  WRITELN('Stack Empty?: ', IsStackEmpty());
  A := 5;
  Push(A);
  A := 4;
  Push(A);
  A := 3;
  Push(A);
  A := 1;
  Push(A);
  A := 2;
  Push(A);
  A := 0;
  Push(A);
  WRITELN('Top: ', GetTop());
  WRITELN('POP: ', Pop());
  WRITELN('POP: ', Pop());
  WRITELN('POP: ', Pop());
  WRITELN('POP: ', Pop());
  WRITELN('POP: ', Pop());
  WRITELN('Stack Empty?: ', IsStackEmpty());
  WRITELN('POP: ', Pop());
  WRITELN('Stack Empty?: ', IsStackEmpty())
END.
