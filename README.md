# Checkout_qt

<img width="359" alt="Gui" src="https://user-images.githubusercontent.com/73497298/177056126-35b37860-8374-486f-ac49-ecc29b9f96ca.png">
<img width="359" alt="About" src="https://user-images.githubusercontent.com/73497298/177056165-ebf867e4-5e01-4690-9bdd-14d18a22fa56.png">

<img width="619" alt="Test_case" src="https://user-images.githubusercontent.com/73497298/177056131-87dcd957-29c4-4147-8580-c0317d6718be.png">

## CI

This repository includes a GitHub Actions workflow at `.github/workflows/ci.yml`.

The workflow runs on Windows and does the following:

- installs MSYS2, MinGW, and Qt 5
- builds the Qt GUI application from `CheckOut.pro`
- builds the GoogleTest target from `unit test/CheckOutTests.pro`
- runs the unit-test executable

If you push this project to GitHub, the workflow will run automatically on every push and pull request.
