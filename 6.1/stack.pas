UNIT stack;


INTERFACE
  TYPE
    DataType = CHAR;
   
  PROCEDURE Push(Elem: DataType);
  FUNCTION Pop(): DataType;
  FUNCTION GetTop(): DataType;
  FUNCTION IsStackEmpty(): BOOLEAN;
    
IMPLEMENTATION

  TYPE
  NodeQ = ^Stack; 
  Stack = RECORD
            Next: NodeQ;
            Data: DataType
          END;
  VAR
    StackQ: NodeQ;
  
  PROCEDURE Push(Elem: DataType);
  VAR
    NewElem: NodeQ;
  BEGIN
    NewElem := StackQ;
    NEW(NewElem);
    NewElem^.Data := Elem;
    IF (StackQ <> NIL)
    THEN
      BEGIN
        NewElem^.Next := StackQ;
        StackQ := NewElem;
      END
    ELSE
      BEGIN
        NewElem^.Next := NIL;
        StackQ := NewElem
      END
  END;
  
  FUNCTION Pop(): DataType;
  VAR
    NextElem: NodeQ;
    Elem: DataType;
  BEGIN
    IF(StackQ <> NIL)
    THEN
      BEGIN
        NextElem := StackQ^.Next;
        Elem := StackQ^.Data;
        DISPOSE(StackQ);
        StackQ := NextElem
      END;
      //WRITE('Stack already empty');
    Pop := Elem
  END;
  
  FUNCTION GetTop(): DataType;
  VAR
    Elem: DataType;
  BEGIN
    IF(StackQ <> NIL)
    THEN
        Elem := StackQ^.Data
    ELSE
      WRITE('Stack already empty');
    GetTop := Elem
  END;
  
  FUNCTION IsStackEmpty(): BOOLEAN;
  BEGIN
    IF(StackQ = NIL)
    THEN
      IsStackEmpty := TRUE
    ELSE
      IsStackEmpty := FALSE  
  END;
  
  
  
BEGIN
END.
