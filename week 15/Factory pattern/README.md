# Factory pattern

**Creational type**

- create object without exposing the creation logic to the user(for example: other devs using the library)
- create NEW object without changing the client logic or recompile client code

*used in mocks for units tests, ORMs, etc.*

**Identification**: Factory methods can be recognized by creation methods, which create objects from concrete classes, but return them as objects of abstract type or interface.