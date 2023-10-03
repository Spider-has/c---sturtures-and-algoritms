UNIT QUEUE;

INTERFACE
  TYPE
    DataType = INTEGER;

  FUNCTION Pop(): DataType;
  PROCEDURE Push(Elem: DataType);
  FUNCTION IsQueueEmpty(): BOOLEAN; 

IMPLEMENTATION
  TYPE
    NodeQ = ^Queue;
    Queue = RECORD
              Next: NodeQ;
              Data: DataType
            END;
  VAR
    Head, Tail: NodeQ;
    
  
  FUNCTION Pop(): DataType;
  VAR
    CopyQ: NodeQ;
    Elem: DataType;  
  BEGIN
    IF Head <> NIL
    THEN
      BEGIN
        CopyQ := Head;
        Elem := Head^.Data;
        Head := Head^.Next;
        DISPOSE(CopyQ)
      END;
    Pop := Elem
  END;
  
  PROCEDURE Push(Elem: DataType);
  VAR
    CopyQ: NodeQ;
  BEGIN
    New(CopyQ);
    CopyQ^.Next := NIL;
    CopyQ^.Data := Elem;
    IF(Head = NIL)
    THEN
      Head := CopyQ
    ELSE 
      Tail^.Next := CopyQ;
    Tail := CopyQ    
  END;
  
  FUNCTION IsQueueEmpty(): BOOLEAN;
  BEGIN
    IsQueueEmpty := Head = NIL
  END;
  
BEGIN
  Head := NIL;
  Tail := NIL
END.
