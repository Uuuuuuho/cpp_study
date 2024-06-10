# NVIDIA CUDA Toolkit Path (update this with your CUDA Toolkit path)
CUDA_PATH = "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.0/"

# Compiler
NVCC = $(CUDA_PATH)/bin/nvcc.exe

# Flags
CXXFLAGS = -O2
NVCCFLAGS = -O2

# Include and Library Paths (update with your project paths)
INC_DIRS = -I. -I$(CUDA_PATH)/include -I../../Common
LIB_DIRS = -L$(CUDA_PATH)/lib/x64

# Libraries
LIBS = -lcuda

# Source files
NAME = asyncAPI
SRCS = $(NAME).cu

# Output executable
TARGET = $(NAME).exe

# Makefile rules
all: $(TARGET)

$(TARGET): $(SRCS)
	$(NVCC) $(CXXFLAGS) $(NVCCFLAGS) $(INC_DIRS) $(LIB_DIRS) $(LIBS) $^ -o $@

clean:
	rm $(TARGET) $(NAME).py $(NAME).lib

