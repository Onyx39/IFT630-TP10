CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
CPPFLAGS = -I/opt/homebrew/opt/llvm/include
LDFLAGS = -L/opt/homebrew/opt/llvm/lib -L/opt/homebrew/opt/llvm/lib/c++
LDLIBS = -lm -lstdc++ -Wl,-rpath,/opt/homebrew/opt/llvm/lib

OPENMP_FLAGS = -fopenmp

SRCS = calcul_integrale_simple.c calcul_integrale_parallele.c calcul_integrale_openmp.c
OBJS = $(SRCS:.c=.o)
EXECUTABLES = calcul_integrale_simple calcul_integrale_parallele calcul_integrale_openmp
ARCHIVE_NAME = paum1202_ricv1301_remise_tp_10_IFT630_H24.zip

all: $(EXECUTABLES)

calcul_integrale_simple: calcul_integrale_simple.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)

calcul_integrale_parallele: calcul_integrale_parallele.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)

calcul_integrale_openmp: calcul_integrale_openmp.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OPENMP_FLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(EXECUTABLES) $(OBJS) $(ARCHIVE_NAME)

archive:
	zip $(ARCHIVE_NAME) $(SRCS) Makefile

run: calcul_integrale_simple calcul_integrale_parallele calcul_integrale_openmp
	@echo "Running calcul_integrale_simple:"
	./calcul_integrale_simple
	@echo "Running calcul_integrale_parallele:"
	./calcul_integrale_parallele
	@echo "Running calcul_integrale_openmp:"
	./calcul_integrale_openmp
