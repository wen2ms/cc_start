#include <iostream>

class Cpu {
  public:
    virtual ~Cpu() {}

    virtual void calculate() const = 0;
};

class Memory {
  public:
    virtual ~Memory() {}

    virtual void store() const = 0;
};

class Gpu {
  public:
    virtual ~Gpu() {}

    virtual void display() const = 0;
};

class IntelCpu : public Cpu {
  public:
    void calculate() const override {
        std::cout << "Intel cpu called\n";
    }
};

class AmdCpu : public Cpu {
  public:
    void calculate() const override {
        std::cout << "Amd cpu called\n";
    }
};

class SamsungMemory : public Memory {
  public:
    void store() const override {
        std::cout << "Samsung memory called\n";
    }
};

class KingstonMemory : public Memory {
  public:
    void store() const override {
        std::cout << "Kingston memory called\n";
    }
};

class NvidiaGpu : public Gpu {
  public:
    void display() const override {
        std::cout << "Nvidia gpu called\n";
    }
};

class AmdGpu : public Gpu {
  public:
    void display() const override {
        std::cout << "Amd gpu called\n";
    }
};

class Computer {
  public:
    Computer(Cpu* cpu, Memory* memory, Gpu* gpu) : cpu_(cpu), memory_(memory), gpu_(gpu) {}

    ~Computer() {
        delete cpu_;
        delete memory_;
        delete gpu_;
    }

    void run() const {
        cpu_->calculate();
        memory_->store();
        gpu_->display();
    }

  private:
    Cpu* cpu_;
    Memory* memory_;
    Gpu* gpu_;
};

int main() {
    std::cout << "I generated an example of computer assembly.\n";
    std::cout << "------------------------------\n";

    Computer* computer1 = new Computer(new IntelCpu, new KingstonMemory, new NvidiaGpu);
    Computer* computer2 = new Computer(new AmdCpu, new SamsungMemory, new AmdGpu);
    Computer* computer3 = new Computer(new IntelCpu, new SamsungMemory, new AmdGpu);

    computer1->run();
    std::cout << "-----------\n";
    computer2->run();
    std::cout << "-----------\n";
    computer3->run();

    delete computer1;
    delete computer2;
    delete computer3;

    std::cout << "------------------------------\n";

    return 0;
}