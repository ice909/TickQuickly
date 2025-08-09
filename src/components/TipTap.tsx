import {useEditor, EditorContent} from '@tiptap/react'
import StarterKit from '@tiptap/starter-kit'

interface TipTapProps {
  content?: string;
  contentUpdate: (content: string) => void;
  onBlur: () => void;
}

export function Tiptap(props: TipTapProps, ) {
  const editor = useEditor({
    extensions: [
      StarterKit.configure({

        orderedList: {
          keepMarks: true,
          HTMLAttributes: {
            class: "list-decimal ml-[1rem]"
          }
        }
      })
    ],
    editorProps: {
      attributes: {
        class: 'min-h-[30vh] focus:outline-none whitespace-pre-wrap',
      },
    },
    content: props.content,
    onUpdate({editor}) {
      props.contentUpdate(editor.getHTML())
    },
    onBlur() {
      // props.contentUpdate(editor.getHTML())
      props.onBlur()
    }
  })

  return (
    <div className="mt-[14px] bg-muted/50 rounded-md p-3">
      <EditorContent editor={editor}/>
    </div>
  )
}