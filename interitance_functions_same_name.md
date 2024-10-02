### Summary of Function Behavior:

| Scenario                         | Virtual Function      | Non-Virtual Function  | Overloading in Derived Class    |
|----------------------------------|-----------------------|-----------------------|---------------------------------|
| **Same function name & signature** | Overrides base class function | Hides base class function | Functions are treated independently |
| **Different signatures (overloading)** | Both functions exist; no overriding | Derived class function hides base | Use `using` to bring base function into scope |
