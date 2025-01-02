vim.notify("nvim dap local", vim.log.levels.INFO, nil)
local dap = require("dap")

local codelldb = vim.fn.expand("$HOME/.local/share/nvim/mason/bin/codelldb")

dap.adapters.gdb = {
	type = "executable",
	command = "gdb",
	args = { "--interpreter=dap", "--eval-command", "set print pretty on" },
}

dap.configurations.c = {
	{
		name = "Launch",
		type = "gdb",
		request = "launch",
		program = vim.fn.getcwd() .. "/build/FastPegSolitaire",
		-- program = function()
		-- 	return vim.fn.input({
		-- 		prompt = "Path to Debuggable Executable: ",
		-- 		default = vim.fn.getcwd() .. "/",
		-- 		completion = "file",
		-- 	})
		-- end,
		cwd = "${workspaceFolder}",
		stopOnEntry = false,
		runInTerminal = true,
		args = {},
	},
}

dap.configurations.cpp = dap.configurations.c
