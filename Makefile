.PHONY: clean All

All:
	@echo "----------Building project:[ QuantLibEx - Debug ]----------"
	@"$(MAKE)" -f  "QuantLibEx.mk"
clean:
	@echo "----------Cleaning project:[ QuantLibEx - Debug ]----------"
	@"$(MAKE)" -f  "QuantLibEx.mk" clean
