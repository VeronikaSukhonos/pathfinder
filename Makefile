PATHFINDER := pathfinder
LIBMX := libmx.a

INCDIR := inc
SRCDIR := src
OBJDIR := obj
LIBDIR := libmx

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

CC := clang
CFLAGS := -std=c11 -Wall -Wextra -Werror -Wpedantic -I$(LIBDIR)/$(INCDIR) -I$(INCDIR)

all: $(PATHFINDER)

$(PATHFINDER): $(LIBDIR)/$(LIBMX) $(OBJS)
	$(CC) -o $@ $(OBJS) -L$(LIBDIR) -lmx

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBDIR)/$(LIBMX): $(wildcard $(LIBDIR)/$(SRCDIR)/*.c)
	make -C $(LIBDIR)

uninstall:
	rm -rf $(PATHFINDER) $(OBJDIR)
	make uninstall -C $(LIBDIR)

clean:
	rm -rf $(OBJDIR)
	make clean -C $(LIBDIR)

reinstall: uninstall all

