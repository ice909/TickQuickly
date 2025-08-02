import { defineConfig } from 'unocss'

export default defineConfig({
  theme: {
    colors: {
      background: 'var(--background)',
      foreground: 'var(--foreground)',
      borderColor: 'var(--border)',
      muted: 'var(--muted)',
      'muted-foreground': 'var(--muted-foreground)',
    },
  }
})